
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(preprocessor CXX C ASM)

set(CMAKE_CXX_COMPILER /usr/bin/g++-9)

FILE(GLOB_RECURSE preprocessor_src "sources/*.cpp" "sources/*.h")

ADD_EXECUTABLE(preprocessor ${preprocessor_src})

target_include_directories(preprocessor PRIVATE "sources" )

set_property(TARGET preprocessor PROPERTY CXX_STANDARD 17)
