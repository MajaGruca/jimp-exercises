
project(p)

set(HEDEAR_FILES P.h)
set(SOURCE_FILES P.cpp)

add_library(libp STATIC ${SOURCE_FILES})
target_include_directories(libp PUBLIC .)

add_executable(p ${SOURCE_FILES} main.cpp)

target_link_libraries(p libp)

