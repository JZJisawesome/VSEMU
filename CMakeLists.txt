#Based on rv32esim CMakeLists.txt

#Common options
cmake_minimum_required(VERSION 3.21)
project(vsemu VERSION 0.1)
#Needed for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#https://stackoverflow.com/questions/41361631/optimize-in-cmake-by-default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

#-I is not needed to compile but is needed for clangd to find the include directory
#set(CMAKE_C_FLAGS "-I include -Wall -Wextra -g3 -mavx -mavx2 -mavx512f")
#set(CMAKE_C_FLAGS "-I include -Wall -Wextra -g3 -mavx -mavx2 -mfma")
#set(CMAKE_C_FLAGS "-I include -Wall -Wextra -g3 -mavx -mavx2)
#set(CMAKE_C_FLAGS "-I include -Wall -Wextra -g3 -mavx")
set(CMAKE_C_FLAGS "-I include -Wall -Wextra -g3")
#set(CMAKE_C_FLAGS "-I include -Wall -Wextra -g3 -mno-sse2")
set(CMAKE_C_FLAGS_DEBUG "-O0")
set(CMAKE_C_FLAGS_RELEASE "-DNDEBUG -Ofast -flto=auto -fuse-linker-plugin -floop-nest-optimize -fipa-pta -fno-semantic-interposition -fdevirtualize-at-ltrans -fno-plt -fstdarg-opt -frename-registers -fweb -ftree-vectorize")

#vsemu Library Targets
#set(RV32ESIM_UNSAFE 0)#Speed boost; may cause out of bounds/etc problems if programs executing on the simulator go out-of-bounds/etc
#set(RV32ESIM_DISABLE_LOGGING 0)#Speed boost (avoid checking if enabled, allows compiler to optimize some things more, etc)
#set(RV32ESIM_C 0)#Support compressed extension

set(VSEMU_SOURCES src/libvsemu/state_lifetime.c src/libvsemu/logging.c src/libvsemu/logging.h src/libvsemu/tick.c src/libvsemu/execute.c src/libvsemu/memory.c src/libvsemu/version.c src/libvsemu/common.h src/libvsemu/registers.h include/libvsemu.h src/libvsemu/libvsemu.version)

if (CMAKE_C_BYTE_ORDER STREQUAL LITTLE_ENDIAN)
    set(IS_LITTLE_ENDIAN 1)
else()
    set(IS_LITTLE_ENDIAN 0)
endif()

configure_file(src/libvsemu/version.c.in src/libvsemu/version.c)

add_library(vsemu_shared SHARED ${VSEMU_SOURCES})
add_library(vsemu_static STATIC ${VSEMU_SOURCES})
target_include_directories(vsemu_shared PRIVATE include ${CMAKE_CURRENT_BINARY_DIR}/src/libvsemu)
target_include_directories(vsemu_static PRIVATE include ${CMAKE_CURRENT_BINARY_DIR}/src/libvsemu)
set_property(TARGET vsemu_shared PROPERTY OUTPUT_NAME vsemu)
set_property(TARGET vsemu_static PROPERTY OUTPUT_NAME vsemu)
set(CMAKE_SHARED_LINKER_FLAGS ${CMAKE_SHARED_LINKER_FLAGS} "-Wl,--version-script=${CMAKE_SOURCE_DIR}/src/libvsemu/libvsemu.version")
#Dosn't work unfortunately
#set(CMAKE_STATIC_LINKER_FLAGS ${CMAKE_STATIC_LINKER_FLAGS} "-Wl,--version-script=${CMAKE_SOURCE_DIR}/src/libvsemu/libvsemu.version")

#vsemu CLI
set(VSEMU_CLI_SOURCES src/cli/main.c include/libvsemu.h)
add_executable(vsemu-cli ${VSEMU_CLI_SOURCES})
target_include_directories(vsemu-cli PRIVATE include)
target_link_libraries(vsemu-cli vsemu_shared)

#These don't work at stopping hidden symbols from being exported from the static library
#target_link_libraries(vsemu vsemu_static)
#set_target_properties(vsemu PROPERTIES C_VISIBILITY_PRESET hidden)
#target_link_options(vsemu PRIVATE -Wl,--exclude-libs=ALL)

