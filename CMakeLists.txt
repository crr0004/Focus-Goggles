cmake_minimum_required(VERSION 3.2)
project(Focus-Goggles)
set(CMAKE_INSTALL_PREFIX "install" CACHE PATH "")

set(WinDivert_Location "${CMAKE_CURRENT_SOURCE_DIR}/../libs/WinDivert-1.1.8-MINGW/" CACHE PATH "WinDivert Root Directory")

add_subdirectory(src)
add_subdirectory(test)


