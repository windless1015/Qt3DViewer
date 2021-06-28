cmake_minimum_required(VERSION 3.5)

project(Qt3DViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets OpenGL REQUIRED)

find_package(OpenMesh REQUIRED)

list(APPEND EXTRA_LIBS OpenGL32.lib)

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

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TestTabWidget
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Qt3DViewer SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Qt3DViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Qt3DViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGL OpenMeshCore OpenMeshTools ${EXTRA_LIBS})

set_target_properties(Qt3DViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Qt3DViewer)
endif()
