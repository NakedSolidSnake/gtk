cmake_minimum_required(VERSION 3.7.0)

project(Application)

set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_PATCH 0)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_EXE_LINKER_FLAGS "-rdynamic")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

find_package (PkgConfig)
if (PKG_CONFIG_FOUND)
    pkg_check_modules (GTK "gtk+-3.0")
    if (GTK_FOUND)
        add_executable(application "")
        target_sources(application
        PUBLIC 
            ${CMAKE_CURRENT_LIST_DIR}/src/main.c 
        )
        target_link_libraries(application PUBLIC ${GTK_LIBRARIES})
        add_definitions(${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})
    endif ()
endif ()

add_custom_command(TARGET application POST_BUILD 
                   COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/glade ${CMAKE_BINARY_DIR}/bin/glade)           