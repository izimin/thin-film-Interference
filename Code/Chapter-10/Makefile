#
# Makefile to build examples for chapter 10 for Linux
#
# Author: Alex V. Boreskoff, <steps3d@narod.ru>
#

include ../make.inc

ALL = rc-specular-torus-1 rc-specular-torus-2 rc-specular-torus-3 rc-specular-torus-4
all: $(ALL)

rc-specular-torus-1: rc-specular-torus-1.o Matrix4x4.o Torus-1.o $(OBJS)
	cc $(LDFLAGS) rc-specular-torus-1.o Matrix4x4.o Torus-1.o $(OBJS) -o rc-specular-torus-1 $(LIBS) -lc

rc-specular-torus-2: rc-specular-torus-2.o Matrix4x4.o Torus-2.o $(OBJS)
	cc $(LDFLAGS) rc-specular-torus-2.o Matrix4x4.o Torus-2.o $(OBJS) -o rc-specular-torus-2 $(LIBS) -lc

rc-specular-torus-3: rc-specular-torus-3.o Matrix4x4.o Torus-3.o $(OBJS)
	cc $(LDFLAGS) rc-specular-torus-3.o Matrix4x4.o Torus-3.o $(OBJS) -o rc-specular-torus-3 $(LIBS) -lc

rc-specular-torus-4: rc-specular-torus-4.o Matrix4x4.o Torus-4.o $(OBJS)
	cc $(LDFLAGS) rc-specular-torus-4.o Matrix4x4.o Torus-4.o $(OBJS) -o rc-specular-torus-4 $(LIBS) -lc

clean:
	rm -r -f $(ALL) $(OBJS) rc-specular-torus-1.o rc-specular-torus-2.o rc-specular-torus-3.o rc-specular-torus-4.o Torus-1.o Torus-2.o Torus-3.o Torus-4.o Matrix4x4.o 2> /dev/nul

include ../rules.linux
