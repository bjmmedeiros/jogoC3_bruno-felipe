#############################################################################
# Makefile for building: Sokoban
# Generated by qmake (2.01a) (Qt 4.8.1) on: Sat Jul 7 14:55:15 2012
# Project:  Sokoban.pro
# Template: app
# Command: /home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake -spec ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile Sokoban.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ -I. -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/include/QtCore -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/include/QtGui -I../../../QtSDK/Desktop/Qt/4.8.1/gcc/include -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib
LIBS          = $(SUBLIBS)  -L/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib -lQtGui -L/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib -L/usr/X11R6/lib -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		block.cpp \
		map.cpp \
		scenegrid.cpp moc_mainwindow.cpp \
		moc_block.cpp \
		moc_scenegrid.cpp
OBJECTS       = main.o \
		mainwindow.o \
		block.o \
		map.o \
		scenegrid.o \
		moc_mainwindow.o \
		moc_block.o \
		moc_scenegrid.o
DIST          = ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		Sokoban.pro
QMAKE_TARGET  = Sokoban
DESTDIR       = 
TARGET        = Sokoban

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: Sokoban.pro  ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++/qmake.conf ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf \
		../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf \
		/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl \
		/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl
	$(QMAKE) -spec ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile Sokoban.pro
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/unix.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/linux.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/gcc-base-unix.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-base.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/common/g++-unix.conf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/qconfig.pri:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/modules/qt_webkit_version.pri:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_functions.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt_config.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/exclusive_builds.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_pre.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/debug.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/default_post.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/declarative_debug.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/gdb_dwarf_index.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/warn_on.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/qt.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/unix/thread.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/moc.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/resources.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/uic.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/yacc.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/lex.prf:
../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/features/include_source_dir.prf:
/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtGui.prl:
/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec ../../../QtSDK/Desktop/Qt/4.8.1/gcc/mkspecs/linux-g++ CONFIG+=debug CONFIG+=declarative_debug -o Makefile Sokoban.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/Sokoban1.0.0 || $(MKDIR) .tmp/Sokoban1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/Sokoban1.0.0/ && $(COPY_FILE) --parents mainwindow.h block.h map.h scenegrid.h .tmp/Sokoban1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp block.cpp map.cpp scenegrid.cpp .tmp/Sokoban1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/Sokoban1.0.0/ && (cd `dirname .tmp/Sokoban1.0.0` && $(TAR) Sokoban1.0.0.tar Sokoban1.0.0 && $(COMPRESS) Sokoban1.0.0.tar) && $(MOVE) `dirname .tmp/Sokoban1.0.0`/Sokoban1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/Sokoban1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_block.cpp moc_scenegrid.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_block.cpp moc_scenegrid.cpp
moc_mainwindow.cpp: map.h \
		block.h \
		mainwindow.h
	/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_block.cpp: block.h
	/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) block.h -o moc_block.cpp

moc_scenegrid.cpp: scenegrid.h
	/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/bin/moc $(DEFINES) $(INCPATH) scenegrid.h -o moc_scenegrid.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui
	/home/aguiar/QtSDK/Desktop/Qt/4.8.1/gcc/bin/uic mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		map.h \
		block.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		map.h \
		block.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

block.o: block.cpp block.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o block.o block.cpp

map.o: map.cpp map.h \
		block.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o map.o map.cpp

scenegrid.o: scenegrid.cpp scenegrid.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o scenegrid.o scenegrid.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_block.o: moc_block.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_block.o moc_block.cpp

moc_scenegrid.o: moc_scenegrid.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_scenegrid.o moc_scenegrid.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

