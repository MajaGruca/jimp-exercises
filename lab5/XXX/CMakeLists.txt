project(XXX)

set(HEDEAR_FILES XXX.h)
set(SOURCE_FILES XXX.cpp)

add_library(libXXX STATIC ${SOURCE_FILES})
target_include_directories(libXXX PUBLIC .)

add_executable(XXX ${SOURCE_FILES} main.cpp)

target_link_libraries(XXX libXXX)
