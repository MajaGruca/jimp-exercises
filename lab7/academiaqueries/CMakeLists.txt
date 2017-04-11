
project(studyyear)

set(HEDEAR_FILES StudyYear.h Student.h StudentRepositoryQueries.h StudentRepository.h)
set(SOURCE_FILES StudyYear.cpp Student.cpp StudentRepositoryQueries.cpp StudentRepository.cpp)

add_library(libstudyyear STATIC ${SOURCE_FILES})
target_include_directories(libstudyyear PUBLIC .)

add_executable(studyyear ${SOURCE_FILES} main.cpp)

target_link_libraries(studyyear libstudyyear)

