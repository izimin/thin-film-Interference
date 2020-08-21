//
// define OpenGL extensions function pointer types for Mac OS X to be compatible with rest OSes
//

#ifndef	__MACOSX_EXTS_RENAME__
#define	__MACOSX_EXTS_RENAME__

typedef	glFogCoordfEXTProcPtr					PFNGLFOGCOORDFEXTPROC;

typedef	glSecondaryColor3fEXTProcPtr			PFNGLSECONDARYCOLOR3FPROC;
typedef	glSecondaryColor3fvEXTProcPtr			PFNGLSECONDARYCOLOR3FVPROC;
typedef	glSecondaryColorPointerEXTProcPtr		PFNGLSECONDARYCOLORPOINTERPROC;

typedef	glCombinerParameterfvNVProcPtr			PFNGLCOMBINERPARAMETERFVNVPROC;
typedef	glCombinerParameterivNVProcPtr			PFNGLCOMBINERPARAMETERIVNVPROC;
typedef	glCombinerParameterfNVProcPtr			PFNGLCOMBINERPARAMETERFNVPROC;
typedef	glCombinerParameterivNVProcPtr			PFNGLCOMBINERPARAMETERINVPROC;
typedef	glCombinerInputNVProcPtr				PFNGLCOMBINERINPUTNVPROC;
typedef	glCombinerOutputNVProcPtr				PFNGLCOMBINEROUTPUTNVPROC;
typedef	glFinalCombinerInputNVProcPtr			PFNGLFINALCOMBINERINPUTNVPROC;

typedef	glBindBufferARBProcPtr					PFNGLBINDBUFFERARBPROC;
typedef	glDeleteBuffersARBProcPtr				PFNGLDELETEBUFFERSARBPROC;
typedef	glGenBuffersARBProcPtr					PFNGLGENBUFFERSARBPROC;
typedef	glIsBufferARBProcPtr					PFNGLISBUFFERARBPROC;
typedef	glBufferDataARBProcPtr					PFNGLBUFFERDATAARBPROC;
typedef	glBufferSubDataARBProcPtr				PFNGLBUFFERSUBDATAARBPROC;
typedef	glGetBufferSubDataARBProcPtr			PFNGLGETBUFFERSUBDATAARBPROC;
typedef	glMapBufferARBProcPtr					PFNGLMAPBUFFERARBPROC;
typedef	glUnmapBufferARBProcPtr					PFNGLUNMAPBUFFERARBPROC;
typedef	glGetBufferParameterivARBProcPtr		PFNGLGETBUFFERPARAMETERIVARBPROC;
typedef	glGetBufferPointervARBProcPtr			PFNGLGETBUFFERPOINTERVARBPROC;

typedef void (*PFNGLGENOCCLUSIONQUERIESNVPROC) (GLsizei n, GLuint *ids);
typedef void (*PFNGLDELETEOCCLUSIONQUERIESNVPROC) (GLsizei n, const GLuint *ids);
typedef GLboolean (*PFNGLISOCCLUSIONQUERYNVPROC) (GLuint id);
typedef void (*PFNGLBEGINOCCLUSIONQUERYNVPROC) (GLuint id);
typedef void (*PFNGLENDOCCLUSIONQUERYNVPROC) (void);
typedef void (*PFNGLGETOCCLUSIONQUERYIVNVPROC) (GLuint id, GLenum pname, GLint *params);
typedef void (*PFNGLGETOCCLUSIONQUERYUIVNVPROC) (GLuint id, GLenum pname, GLuint *params);

typedef	glGenProgramsARBProcPtr					PFNGLGENPROGRAMSARBPROC;
typedef	glDeleteProgramsARBProcPtr				PFNGLDELETEPROGRAMSARBPROC;
typedef	glBindProgramARBProcPtr					PFNGLBINDPROGRAMARBPROC;
typedef	glIsProgramARBProcPtr					PFNGLISPROGRAMARBPROC;
typedef	glProgramStringARBProcPtr				PFNGLPROGRAMSTRINGARBPROC;
typedef	glGetProgramivARBProcPtr				PFNGLGETPROGRAMIVARBPROC;
typedef	glVertexAttrib4fARBProcPtr				PFNGLVERTEXATTRIB4FARBPROC;
typedef	glVertexAttrib4fvARBProcPtr				PFNGLVERTEXATTRIB4FVARBPROC;
typedef	glVertexAttrib3fARBProcPtr				PFNGLVERTEXATTRIB3FARBPROC;
typedef	glVertexAttrib3fvARBProcPtr				PFNGLVERTEXATTRIB3FVARBPROC;
typedef	glEnableVertexAttribArrayARBProcPtr		PFNGLENABLEVERTEXATTRIBARRAYARBPROC;
typedef	glDisableVertexAttribArrayARBProcPtr	PFNGLDISABLEVERTEXATTRIBARRAYARBPROC;
typedef	glProgramLocalParameter4fARBProcPtr		PFNGLPROGRAMLOCALPARAMETER4FARBPROC;
typedef	glProgramLocalParameter4fvARBProcPtr	PFNGLPROGRAMLOCALPARAMETER4FVARBPROC;
typedef	glGetProgramLocalParameterfvARBProcPtr	PFNGLGETPROGRAMLOCALPARAMETERFVARBPROC;
typedef	glProgramEnvParameter4fARBProcPtr		PFNGLPROGRAMENVPARAMETER4FARBPROC;
typedef	glProgramEnvParameter4fvARBProcPtr		PFNGLPROGRAMENVPARAMETER4FVARBPROC;
typedef	glGetProgramEnvParameterfvARBProcPtr	PFNGLGETPROGRAMENVPARAMETERFVARBPROC;
typedef	glVertexAttribPointerARBProcPtr			PFNGLVERTEXATTRIBPOINTERARBPROC;
typedef	glGetVertexAttribfvARBProcPtr			PFNGLGETVERTEXATTRIBFVARBPROC;

typedef	glTexImage3DEXTProcPtr					PFNGLTEXIMAGE3DEXTPROC;

typedef	glCompressedTexImage3DARBProcPtr		PFNGLCOMPRESSEDTEXIMAGE3DARBPROC;
typedef	glCompressedTexImage2DARBProcPtr		PFNGLCOMPRESSEDTEXIMAGE2DARBPROC;
typedef	glCompressedTexImage1DARBProcPtr		PFNGLCOMPRESSEDTEXIMAGE1DARBPROC;
typedef	glCompressedTexSubImage3DARBProcPtr		PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC;
typedef	glCompressedTexSubImage2DARBProcPtr		PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC;
typedef	glCompressedTexSubImage1DARBProcPtr		PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC;
typedef	glGetCompressedTexImageARBProcPtr		PFNGLGETCOMPRESSEDTEXIMAGEARBPROC;

typedef	glPointParameterfARBProcPtr				PFNGLPOINTPARAMETERFARBPROC;
typedef	glPointParameterfvARBProcPtr			PFNGLPOINTPARAMETERFVARBPROC;

typedef	glGenQueriesARBProcPtr					PFNGLGENQUERIESARBPROC;
typedef	glDeleteQueriesARBProcPtr				PFNGLDELETEQUERIESARBPROC;
typedef	glIsQueryARBProcPtr						PFNGLISQUERYARBPROC;
typedef	glBeginQueryARBProcPtr					PFNGLBEGINQUERYARBPROC;
typedef	glGenQueriesARBProcPtr					PFNGENQUERIESARBPROC;
typedef	glEndQueryARBProcPtr					PFNGLENDQUERYARBPROC;
typedef	glGetQueryivARBProcPtr					PFNGLGETQUERYIVARBPROC;
typedef	glGetQueryObjectivARBProcPtr			PFNGLGETQUERYOBJECTIVARBPROC;
typedef	glGetQueryObjectuivARBProcPtr			PFNGLGETQUERYOBJECTUIVARBPROC;

typedef	glDeleteObjectARBProcPtr				PFNGLDELETEOBJECTARBPROC;
typedef	glGetHandleARBProcPtr					PFNGLGETHANDLEARBPROC;
typedef	glDetachObjectARBProcPtr				PFNGLDETACHOBJECTARBPROC;
typedef	glCreateShaderObjectARBProcPtr			PFNGLCREATESHADEROBJECTARBPROC;
typedef	glShaderSourceARBProcPtr				PFNGLSHADERSOURCEARBPROC;
typedef	glCompileShaderARBProcPtr				PFNGLCOMPILESHADERARBPROC;
typedef	glCreateProgramObjectARBProcPtr			PFNGLCREATEPROGRAMOBJECTARBPROC;
typedef	glAttachObjectARBProcPtr				PFNGLATTACHOBJECTARBPROC;
typedef	glLinkProgramARBProcPtr					PFNGLLINKPROGRAMARBPROC;
typedef	glUseProgramObjectARBProcPtr			PFNGLUSEPROGRAMOBJECTARBPROC;
typedef	glValidateProgramARBProcPtr				PFNGLVALIDATEPROGRAMARBPROC;
typedef	glUniform1fARBProcPtr					PFNGLUNIFORM1FARBPROC;
typedef	glUniform2fARBProcPtr					PFNGLUNIFORM2FARBPROC;
typedef	glUniform3fARBProcPtr					PFNGLUNIFORM3FARBPROC;
typedef	glUniform4fARBProcPtr					PFNGLUNIFORM4FARBPROC;
typedef	glUniform1iARBProcPtr					PFNGLUNIFORM1IARBPROC;
typedef	glUniform2iARBProcPtr					PFNGLUNIFORM2IARBPROC;
typedef	glUniform3iARBProcPtr					PFNGLUNIFORM3IARBPROC;
typedef	glUniform4iARBProcPtr					PFNGLUNIFORM4IARBPROC;
typedef	glUniform1fvARBProcPtr					PFNGLUNIFORM1FVARBPROC;
typedef	glUniform2fvARBProcPtr					PFNGLUNIFORM2FVARBPROC;
typedef	glUniform3fvARBProcPtr					PFNGLUNIFORM3FVARBPROC;
typedef	glUniform4fvARBProcPtr					PFNGLUNIFORM4FVARBPROC;
typedef	glUniform1ivARBProcPtr					PFNGLUNIFORM1IVARBPROC;
typedef	glUniform2ivARBProcPtr					PFNGLUNIFORM2IVARBPROC;
typedef	glUniform3ivARBProcPtr					PFNGLUNIFORM3IVARBPROC;
typedef	glUniform4ivARBProcPtr					PFNGLUNIFORM4IVARBPROC;
typedef	glUniformMatrix2fvARBProcPtr			PFNGLUNIFORMMATRIX2FVARBPROC;
typedef	glUniformMatrix3fvARBProcPtr			PFNGLUNIFORMMATRIX3FVARBPROC;
typedef	glUniformMatrix4fvARBProcPtr			PFNGLUNIFORMMATRIX4FVARBPROC;
typedef	glGetObjectParameterfvARBProcPtr		PFNGLGETOBJECTPARAMETERFVARBPROC;
typedef	glGetObjectParameterivARBProcPtr		PFNGLGETOBJECTPARAMETERIVARBPROC;
typedef	glGetInfoLogARBProcPtr					PFNGLGETINFOLOGARBPROC;
typedef	glGetAttachedObjectsARBProcPtr			PFNGLGETATTACHEDOBJECTSARBPROC;
typedef	glGetUniformLocationARBProcPtr			PFNGLGETUNIFORMLOCATIONARBPROC;
typedef	glGetActiveUniformARBProcPtr			PFNGLGETACTIVEUNIFORMARBPROC;
typedef	glGetUniformfvARBProcPtr				PFNGLGETUNIFORMFVARBPROC;
typedef	glGetUniformivARBProcPtr				PFNGLGETUNIFORMIVARBPROC;
typedef	glGetShaderSourceARBProcPtr				PFNGLGETSHADERSOURCEARBPROC;
typedef	glBindAttribLocationARBProcPtr			PFNGLBINDATTRIBLOCATIONARBPROC;
typedef	glGetActiveAttribARBProcPtr				PFNGLGETACTIVEATTRIBARBPROC;
typedef	glGetAttribLocationARBProcPtr			PFNGLGETATTRIBLOCATIONARBPROC;

typedef	glActiveStencilFaceEXTProcPtr			PFNGLACTIVESTENCILFACEEXTPROC;
typedef	glDepthBoundsEXTProcPtr					PFNGLDEPTHBOUNDSEXTPROC;

typedef	glIsRenderbufferEXTProcPtr						PFNGLISRENDERBUFFEREXTPROC;
typedef	glBindRenderbufferEXTProcPtr					PFNGLBINDRENDERBUFFEREXTPROC;
typedef	glDeleteRenderbuffersEXTProcPtr					PFNGLDELETERENDERBUFFERSEXTPROC;
typedef	glGenRenderbuffersEXTProcPtr					PFNGLGENRENDERBUFFERSEXTPROC;
typedef	glRenderbufferStorageEXTProcPtr					PFNGLRENDERBUFFERSTORAGEEXTPROC;
typedef	glGetRenderbufferParameterivEXTProcPtr			PFNGLGETRENDERBUFFERPARAMETERIVEXTPROC;
typedef	glIsFramebufferEXTProcPtr						PFNGLISFRAMEBUFFEREXTPROC;
typedef	glBindFramebufferEXTProcPtr						PFNGLBINDFRAMEBUFFEREXTPROC;
typedef	glDeleteFramebuffersEXTProcPtr					PFNGLDELETEFRAMEBUFFERSEXTPROC;
typedef	glGenFramebuffersEXTProcPtr						PFNGLGENFRAMEBUFFERSEXTPROC;
typedef	glCheckFramebufferStatusEXTProcPtr				PFNGLCHECKFRAMEBUFFERSTATUSEXTPROC;
typedef	glFramebufferTexture1DEXTProcPtr				PFNGLFRAMEBUFFERTEXTURE1DEXTPROC;
typedef	glFramebufferTexture2DEXTProcPtr				PFNGLFRAMEBUFFERTEXTURE2DEXTPROC;
typedef	glFramebufferTexture3DEXTProcPtr				PFNGLFRAMEBUFFERTEXTURE3DEXTPROC;
typedef	glFramebufferRenderbufferEXTProcPtr				PFNGLFRAMEBUFFERRENDERBUFFEREXTPROC;
typedef	glGetFramebufferAttachmentParameterivEXTProcPtr	PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVEXTPROC;
typedef	glGenerateMipmapEXTProcPtr						PFNGLGENERATEMIPMAPEXTPROC;

#endif