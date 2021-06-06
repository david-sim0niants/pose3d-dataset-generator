cmake_minimum_required(VERSION 3.10)
project(pose3d_dataset_generator)


# find necessary packages
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)


# third party apps
add_subdirectory(third-party/stb)
option(ASSIMP_BUILD_TESTS 0)
add_subdirectory(third-party/assimp)


add_executable(pose3d-gen src/main.cpp src/window.cpp)

target_link_libraries(pose3d-gen PUBLIC OpenGL::GL glfw GLEW::glew glm::glm ${CMAKE_DL_LIBS} -lpthread -lm)
set_target_properties(pose3d-gen PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
