//
// Sample to to specular per-pixel lighting with Register Combiners in OpenGL
//
// Author: Alex V. Boreskoff <alexboreskoff@mtu-net.ru>, <steps3d@narod.ru>
//

#include	"libExt.h"

#ifdef	MACOSX
	#include	<GLUT/glut.h>
#else
	#include	<glut.h>
#endif

#include	<stdio.h>
#include	<stdlib.h>

#include	"libTexture.h"
#include	"Vector3D.h"
#include	"Vector2D.h"

Vector3D	eye   ( 2, 2, 2 );			// camera position
Vector3D	light ( 0.5, 0, 1 );		// light position
unsigned	normCubeMap;				// normalization cubemap id
unsigned	bumpMap;					// normal map
unsigned	decalMap;					// decal (diffuse) texture
float	 	angle = 0;

Vector3D	v  [4];
Vector2D	t0 [4];
Vector3D	t1 [4];

void init ()
{
	glClearColor ( 0.0, 0.0, 0.0, 1.0 );
	glEnable     ( GL_DEPTH_TEST );
	glDepthFunc  ( GL_LEQUAL );

	glHint ( GL_POLYGON_SMOOTH_HINT,         GL_NICEST );
	glHint ( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}

void display ()
{
	float	lightColor   [4] = { 1, 1, 0, 1 };		// yellow light
	float	ambientColor [4] = { 0, 0, 0.5f, 1 };	// dark blue

	glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

												// setup texture units
												// bind bump (normal) map to texture unit 0
	glActiveTextureARB ( GL_TEXTURE0_ARB );
	glEnable           ( GL_TEXTURE_2D );
	glBindTexture      ( GL_TEXTURE_2D, bumpMap );

												// bind normalization cube map to texture unit 1
	glActiveTextureARB ( GL_TEXTURE1_ARB );
	glEnable           ( GL_TEXTURE_CUBE_MAP_ARB );
	glBindTexture      ( GL_TEXTURE_CUBE_MAP_ARB, normCubeMap );

												// setup register combiners
	glEnable                ( GL_REGISTER_COMBINERS_NV );
	glCombinerParameteriNV  ( GL_NUM_GENERAL_COMBINERS_NV, 2 );
	glCombinerParameterfvNV ( GL_CONSTANT_COLOR0_NV, lightColor );
	glCombinerParameterfvNV ( GL_CONSTANT_COLOR1_NV, ambientColor );

												// setup general combiner 0
												// configure A = expand (tex0) (bumpmap)
	glCombinerInputNV ( GL_COMBINER0_NV, GL_RGB, GL_VARIABLE_A_NV, GL_TEXTURE0_ARB,
                        GL_EXPAND_NORMAL_NV, GL_RGB );

												// configure B = expand (tex1) (norm. map)
	glCombinerInputNV ( GL_COMBINER0_NV, GL_RGB, GL_VARIABLE_B_NV, GL_TEXTURE1_ARB,
                        GL_EXPAND_NORMAL_NV, GL_RGB );

												// configure C = 0
	glCombinerInputNV ( GL_COMBINER0_NV, GL_RGB, GL_VARIABLE_C_NV, GL_ZERO,
						GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// configure D = 0
	glCombinerInputNV ( GL_COMBINER0_NV, GL_RGB, GL_VARIABLE_D_NV, GL_ZERO,
						GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// setup output of (h,n)
	glCombinerOutputNV ( GL_COMBINER0_NV, GL_RGB,
							GL_SPARE0_NV,		// AB output
							GL_DISCARD_NV,		// CD output
							GL_DISCARD_NV, 		// sum output
							GL_NONE,			// no scale
							GL_NONE,			// no bias
							GL_TRUE,			// AB = A dot B
							GL_FALSE, GL_FALSE );

												// now spare0.rgb contains (h,n)

												// setup general combiner 1

												// A = max ( (n,h), 0 )
	glCombinerInputNV ( GL_COMBINER1_NV, GL_RGB, GL_VARIABLE_A_NV,
							GL_SPARE0_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// B = max ( (n,h), 0 )
	glCombinerInputNV ( GL_COMBINER1_NV, GL_RGB, GL_VARIABLE_B_NV,
							GL_SPARE0_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// setup output of (h,n)^2
	glCombinerOutputNV ( GL_COMBINER1_NV, GL_RGB,
							GL_SPARE0_NV,		// AB output
							GL_DISCARD_NV,		// CD output
							GL_DISCARD_NV, 		// sum output
							GL_NONE,			// no scale
							GL_NONE,			// no bias
							GL_FALSE,			// we do not need here dot product
							GL_FALSE, GL_FALSE );

												// now spare0.rgb = (n,h) ^ 2

												// configure final combiner

												// A.rgb = EF
	glFinalCombinerInputNV ( GL_VARIABLE_A_NV, GL_E_TIMES_F_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// B.rgb = EF
	glFinalCombinerInputNV ( GL_VARIABLE_B_NV, GL_E_TIMES_F_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// C = 0
	glFinalCombinerInputNV ( GL_VARIABLE_C_NV, GL_ZERO, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// D = constant_color1.rgb
	glFinalCombinerInputNV ( GL_VARIABLE_D_NV, GL_CONSTANT_COLOR1_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// E = spare0.rgb
	glFinalCombinerInputNV ( GL_VARIABLE_E_NV, GL_SPARE0_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// F = spare0.rgb
	glFinalCombinerInputNV ( GL_VARIABLE_F_NV, GL_SPARE0_NV, GL_UNSIGNED_IDENTITY_NV, GL_RGB );

												// G.alpa = 1
	glFinalCombinerInputNV ( GL_VARIABLE_G_NV, GL_ZERO, GL_UNSIGNED_INVERT_NV, GL_ALPHA );

												// so at output we'll get
												// RGB   = max ( (l, n), 0 )^8
												// alpha = 1

												// compute texture coordinates for normalization cibe map
	int	i;
	
	for ( i = 0; i < 4; i++ )
	{
		Vector3D	li = light - v [i];
		Vector3D	vi = eye   - v [i];

		t1 [i] = li.normalize () + vi.normalize ();					// compute vector h
	}
												// now draw quad
	glBegin ( GL_QUADS );

	for ( i = 0; i < 4; i++ )
	{
		glMultiTexCoord2fv ( GL_TEXTURE0_ARB, t0 [i] );
		glMultiTexCoord3fv ( GL_TEXTURE1_ARB, t1 [i] );
	  	glVertex3fv        ( v [i]                   );
	}

	glEnd   ();

	glutSwapBuffers ();
}

void reshape ( int w, int h )
{
   glViewport     ( 0, 0, (GLsizei)w, (GLsizei)h );
   glMatrixMode   ( GL_PROJECTION );
   glLoadIdentity ();
   gluPerspective ( 60.0, (GLfloat)w/(GLfloat)h, 1.0, 60.0 );
   glMatrixMode   ( GL_MODELVIEW );
   glLoadIdentity ();
   gluLookAt      ( eye.x, eye.y, eye.z,	// eye
					0, 0, 0,				// center
					0.0, 0.0, 1.0 );		// up
}

void key ( unsigned char key, int x, int y )
{
	if ( key == 27 || key == 'q' || key == 'Q' )
    	exit ( 0 );
}

void	animate ()
{
	angle  = 0.004f * glutGet ( GLUT_ELAPSED_TIME );

	light.x = 1.75*cos ( angle );
	light.y = 1.75*sin ( angle );
	light.z = 0.75 + 0.1 * sin ( angle / 3 );

	glutPostRedisplay ();
}

int main ( int argc, char * argv [] )
{
							// initialize glut
	glutInit            ( &argc, argv );
	glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
	glutInitWindowSize  ( 500, 500 );


								// create window
	int	win = glutCreateWindow ( "OpenGL per-pixel specular lighting with register combiners" );

								// register handlers
	glutDisplayFunc  ( display );
	glutReshapeFunc  ( reshape );
	glutKeyboardFunc ( key     );
	glutIdleFunc     ( animate );

	init ();

	printfInfo ();

	if ( !isExtensionSupported ( "GL_ARB_multitexture" ) )
	{
		printf ( "ARB_multitexture NOT supported.\n" );

		return 1;
	}

	if ( !isExtensionSupported ( "GL_NV_register_combiners" ) )
	{
		printf ( "NV_register_combiners NOT supported.\n" );

		return 2;
	}

	initExtensions ();

												// setup vertices
	v [0] = Vector3D ( -1.3, -1.3, 0 );
	v [1] = Vector3D (  1.3, -1.3, 0 );
	v [2] = Vector3D (  1.3,  1.3, 0 );
	v [3] = Vector3D ( -1.3,  1.3, 0 );

												// setup texture coordinates for bump map
	t0 [0] = Vector2D ( 0, 0 );
	t0 [1] = Vector2D ( 1, 0 );
	t0 [2] = Vector2D ( 1, 1 );
	t0 [3] = Vector2D ( 0, 1 );

	bumpMap     = createTexture2D            ( true, "../Textures/Bumpmaps/bump.tga" );
	decalMap    = createTexture2D            ( true, "../Textures/block.bmp" );
	normCubeMap = createNormalizationCubemap ( 32 );

	glutMainLoop ();

	return 0;
}
