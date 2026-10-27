cmake_minimum_required(VERSION 3.16)

project(FramelessResizableWidget LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(FramelessResizableWidget
    main.cpp
    FramelessResizableWidget.cpp
    FramelessResizableWidget.h
)

target_link_libraries(FramelessResizableWidget PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
