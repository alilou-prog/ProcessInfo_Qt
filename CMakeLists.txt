cmake_minimum_required(VERSION 3.16)

project(ProcessInfo VERSION 0.1 LANGUAGES CXX)

# enable Qt tools
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find Widgets package
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# make the livrary needed for the app

add_library(SystemAnalyser SHARED
	ProcessInfo/SystemAnalyser.cpp
	ProcessInfo/SystemAnalyser.h
)

add_library(Tree SHARED
	treeitem.h treeitem.cpp
	tree.h tree.cpp
)

# build the app
add_executable(
	ProcessInfo_Qt
	main.cpp
        treemodel.cpp treemodel.h
)

# link dependencies for Tree
target_link_libraries(
        Tree
        PRIVATE Qt6::Core
)

# dependencies for the main app
target_link_libraries(
	ProcessInfo_Qt
	PRIVATE Tree
        PRIVATE SystemAnalyser
	PRIVATE Qt6::Widgets
)



