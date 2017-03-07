project(simpleforwardlist)

set(HEDEAR_FILES ForwardList.h)
set(SOURCE_FILES ForwardList.cpp)

add_library(libsimpleforwardlist STATIC ${SOURCE_FILES})
target_include_directories(libsimpleforwardlist PUBLIC .)

add_executable(simpleforwardlist ${SOURCE_FILES} main.cpp)

target_link_libraries(simpleforwardlist libsimpleforwardlist)
