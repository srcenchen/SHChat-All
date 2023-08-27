include_directories("${PROJECT_SOURCE_DIR}/inc/")
add_subdirectory(src)
add_executable(${EXECUTABLE_NAME} main.cpp ${SOURCE})