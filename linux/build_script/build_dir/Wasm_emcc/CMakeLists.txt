
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(scgms_wasm CXX C ASM)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread -s PTHREAD_POOL_SIZE=3")

FILE(GLOB_RECURSE scgms_srcs "sources/*.c" "sources/*.cpp" "sources/*.h")

ADD_EXECUTABLE(scgms ${scgms_srcs})

target_compile_definitions(scgms PRIVATE WASM=1)
target_compile_definitions(scgms PRIVATE EMBEDDED=1)
target_compile_options(scgms PRIVATE -pthread)


target_include_directories(scgms PRIVATE "sources" )
target_include_directories(scgms PRIVATE "sources/scgms" )
target_include_directories(scgms PRIVATE "sources/filters" )
