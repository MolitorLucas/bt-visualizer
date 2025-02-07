cmake_minimum_required(VERSION 3.16)

project(BTVisualizer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        btvisualizer.cpp
        btvisualizer.h
        btvisualizer.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(BTVisualizer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        BT/node.h
        BT/blackboard.h BT/blackboard.cpp
        BT/tickreturn.h
        BT/composite/compositenode.h BT/composite/compositenode.cpp
        BT/decorator/decoratornode.h BT/decorator/decoratornode.cpp
        BT/composite/sequencenode.h BT/composite/sequencenode.cpp
        BT/composite/selectornode.h BT/composite/selectornode.cpp
        BT/decorator/inverternode.h BT/decorator/inverternode.cpp
        BT/decorator/repeaternode.h BT/decorator/repeaternode.cpp
        BT/conditionnode.h BT/conditionnode.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET BTVisualizer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(BTVisualizer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(BTVisualizer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(BTVisualizer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.BTVisualizer)
endif()
set_target_properties(BTVisualizer PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS BTVisualizer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(BTVisualizer)
endif()
