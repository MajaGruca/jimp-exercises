project(poin)

set(HEDEAR_FILES Point.h)
set(SOURCE_FILES Point.cpp)

add_library(libpoin STATIC ${SOURCE_FILES})
target_include_directories(libpoin PUBLIC .)

add_executable(poin ${SOURCE_FILES} main.cpp)

target_link_libraries(poin libpoin)