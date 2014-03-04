QT+=opengl \
		gui \
		core
INCLUDEPATH+=include \
					 +=ui

INCLUDEPATH+=./include \
             ./include/Objects \
             ./include/MarchingCubes \
             ./include/LASHandler \
             ./include/Maps


OBJECTS_DIR=obj/
MOC_DIR=moc/
TARGET=QtNGL
#QMAKE_CXX=clang++ -fdiagnostics-fixit-info

CONFIG += console
#CONFIG += staticlib link_pkgconfig
#PKGCONFIG += glib-2.0 gupnp-1.0 libxml-2.0

CONFIG -= app_bundle
UI_HEADERS_DIR=ui
SOURCES += \
    src/main.cpp \
    src/MainWindow.cpp \
    src/GLWindow.cpp \
    src/MarchingCubes/GLData.cpp \
    src/MarchingCubes/HashTable.cpp \
    src/MarchingCubes/MarchingCubes.cpp \
    src/MarchingCubes/Object.cpp \
    src/Manager.cpp \
    src/MarchingCubes/Histogram.cpp \
    src/Maps/ThicknessMap.cpp \
    src/Maps/MapsManager.cpp \
    src/Maps/Map.cpp \
    src/Maps/HeightMap.cpp \
    src/Maps/DensityMap.cpp \
    src/Texture.cpp

SOURCES += src/LASHandler/PulseManager.cpp \
    src/LASHandler/Pulse.cpp \
    src/LASHandler/Las1_3_handler.cpp \
    src/LASHandler/Peak.cpp \
    src/LASHandler/QuadTreeNode.cpp

HEADERS += \
    include/MainWindow.h \
    include/GLWindow.h \
    include/LASHandler/Types.h \
    include/LASHandler/PulseManager.h \
    include/LASHandler/Pulse.h \
    include/LASHandler/Las1_3_handler.h \
    include/LASHandler/Peak.h \
    include/LASHandler/QuadTreeNode.h \
    include/Manager.h \
    include/MarchingCubes/GLData.h \
    include/MarchingCubes/HashTable.h \
    include/MarchingCubes/MarchingCubes.h \
    include/MarchingCubes/MCTables.h \
    include/MarchingCubes/Object.h \
    include/MarchingCubes/Histogram.h \
    include/Maps/ThicknessMap.h \
    include/Maps/MapsManager.h \
    include/Maps/Map.h \
    include/Maps/HeightMap.h \
    include/Maps/DensityMap.h \
    include/Texture.h

FORMS += \
    ui/MainWindow.ui

OTHER_FILES+= shaders/Phong.fs \
              shaders/Phong.vs \
    shaders/PhongFragment.glsl \
    shaders/PhongVertex.glsl \
    README.txt \
    shaders/Vertex.vs \
    shaders/Fragment.fs

INCLUDEPATH +=   "/usr/include/eigen3/" \
                 "/usr/include/pcl-1.5/" \
                 "/usr/include/vtk/" \
                 "/usr/include/boost/" \
                 "/usr/include/flann" \
                 "/usr/include/gtkmm-2.4/" \
                 "/usr/include/glibmm-2.4/" \
                 "/usr/include/sigc++-2.0/"
#                 "/users/rsg/arsf/usr/include/lidar/quadtree/"
#                 "/usr/lib/"


LIBS += -lQtGui -lQtCore -lQtOpenGL \
        -L/usr/lib64/vtk -lvtkCommon -lvtksys -lvtkViews -lvtkWidgets  -lvtkRendering -lvtkGraphics -lvtkImaging -lvtkIO -lvtkFiltering -lvtkDICOMParser -lvtkmetaio -lvtkexoIIc -lvtkHybrid \
#        -llzo2 -llaslib -ljemalloc #-llidarquadtree

#prefix=/users/rsg/arsf/usr
#exec_prefix=/users/rsg/arsf/usr
#libdir=/users/rsg/arsf/usr/lib
#includedir=/users/rsg/arsf/usr/include/lidar/quadtree

#Name: lidarquadtree
#Description: Library to handle LIDAR data using a quad tree structure with paging to disk
#URL: http://rsg.pml.ac.uk/
#Version: 1.3
#Requires: laslib
#Libs: -L${libdir} -llidarquadtree
#Cflags: -I${includedir}

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64
macx:INCLUDEPATH+=/usr/local/boost/
linux-g++:QMAKE_CXXFLAGS +=  -march=native
linux-g++-64:QMAKE_CXXFLAGS +=  -march=native
# define the _DEBUG flag for the graphics lib
DEFINES +=NGL_DEBUG

LIBS += -L/usr/local/lib
LIBS += -L/users/rsg/arsf/usr/lib

LIBS +=  -L/$(HOME)/BilLibrary/lib -lBilLibrary
LIBS +=  -L/$(HOME)/NGL/lib -lNGL


#                    -L/$(HOME)/FReps/lib -lFReps \

# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-clang {
    DEFINES += LINUX
    LIBS+= -lGLEW
}
linux-g++ {
    DEFINES += LINUX
    LIBS+= -lGLEW
}

QMAKE_CXXFLAGS += -std=gnu++0x
QMAKE_CXXFLAGS += -std=c++0x
CONFIG += c++11

DEPENDPATH+=include
# if we are on a mac define DARWIN
macx:DEFINES += DARWIN
# this is where to look for includes
INCLUDEPATH += $$(HOME)/NGL/include/

#

INCLUDEPATH += $$(HOME)/BilLibrary/include/


win32: {
        DEFINES+=USING_GLEW
        INCLUDEPATH+=-I c:/boost_1_44_0
        INCLUDEPATH+=-I c:/boost

        INCLUDEPATH+= -I C:/NGL/Support/glew
        LIBS+= -L C:/NGL/lib
        LIBS+= -lmingw32
        DEFINES += WIN32
        DEFINES += USING_GLEW
        DEFINES +=GLEW_STATIC
        DEFINES+=_WIN32
        SOURCES+=C:/NGL/Support/glew/glew.c
        INCLUDEPATH+=C:/NGL/Support/glew/
}
