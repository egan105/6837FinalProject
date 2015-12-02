project(shooting-gallery)

file(GLOB_RECURSE headers "${PROJECT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE sources "${PROJECT_SOURCE_DIR}/src/*.c*")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(shooting-gallery ${sources} ${headers})
target_link_libraries(shooting-gallery ${GLUT_LIBRARY} ${OPENGL_LIBRARY})
