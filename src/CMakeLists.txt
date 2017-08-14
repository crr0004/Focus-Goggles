cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(MAIN_SRC
   	main.cpp
	)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
set(LIBS WinDivert ${GTKMM_LIBRARIES})

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories(${GTKMM_INCLUDE_DIRS})
include_directories("${WinDivert_Location}/include")

link_directories(${GTKMM_LIBRARY_DIRS})
link_directories("${WinDivert_Location}/amd64")

add_executable(main ${MAIN_SRC} rc/main.rc)


target_link_libraries(main ${LIBS})
