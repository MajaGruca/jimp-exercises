
project(ksztalt)

set(HEDEAR_FILES Ksztalt.h Ksztalt.h Trojkat.h Kwadrat.h)
set(SOURCE_FILES Ksztalt.cpp Kolo.cpp Trojkat.cpp Kwadrat.cpp)

add_library(libksztalt STATIC ${SOURCE_FILES})
target_include_directories(libksztalt PUBLIC .)

add_executable(ksztalt ${SOURCE_FILES} main.cpp)

target_link_libraries(ksztalt libksztalt)

