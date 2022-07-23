cmake_minimum_required(VERSION 3.5)

project(Qt3DViewer VERSION 0.1 LANGUAGES CXX)



set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


SET(Qt5_DIR D:/Librarys/Qt/Qt5.12.10/5.12.10/msvc2015_64/lib/cmake/Qt5)
SET(OpenMesh_DIR D:/Librarys/OpenMesh8.1/share/OpenMesh/cmake)


SET(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} Qt5_DIR OpenMesh_DIR)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SEt(CMAKE_AUTOMOC ON)
SEt(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)



FIND_PACKAGE(Qt5 COMPONENTS Core Widgets Gui OpenGL REQUIRED)
FIND_PACKAGE(OpenMesh REQUIRED)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#find_package(Qt5 COMPONENTS Widgets OpenGL REQUIRED)


set(PROJECT_SOURCES
        main.cpp
		Qt3DViewer.cpp
		Qt3DViewer.h
		Qt3DViewer.ui
        Qt3DViewer.qrc
		openmeshApps/MeshViewerWidget.cpp
		openmeshApps/MeshViewerWidget.h
		openmeshApps/MeshViewerWidgetT.h
		openmeshApps/MeshViewerWidgetT_impl.h
		openmeshApps/QGLViewerWidget.h
		openmeshApps/QGLViewerWidget.cpp
)


add_definitions(-D_USE_MATH_DEFINES)


add_executable(Qt3DViewer
    ${PROJECT_SOURCES}
)

TARGET_LINK_DIRECTORIES(${CMAKE_PROJECT_NAME} PUBLIC
	D:/Librarys/OpenMesh8.1/lib
)

#INCLUDE_DIRECTORIES(
	
#)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
	D:/Librarys/OpenMesh8.1/include
	${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries( Qt3DViewer
  Qt5::Core
  Qt5::Widgets  
  Qt5::Gui
  Qt5::OpenGL
  debug OpenMeshCored
  debug OpenMeshToolsd
  optimized OpenMeshCore
  optimized OpenMeshTools
  OpenGL32.lib
)


set_target_properties(Qt3DViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)


message(STATUS {"${OpenMesh_INCLUDE_DIRS}"})