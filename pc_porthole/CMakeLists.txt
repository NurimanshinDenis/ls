cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(PROJECT_NAME pc_porthole )
project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} 
    src/interfaces/i-view-port.h
    src/system/system.h
    src/system/system.cpp
    src/system/view-port/opengl460/opengl460.cpp
	src/system/view-port/opengl460/opengl460.h
    src/system/view-port/opengl460/simple-object-3d.cpp
	src/system/view-port/opengl460/simple-object-3d.h
    src/system/view-port/opengl460/simple-shader-3d.cpp
	src/system/view-port/opengl460/simple-shader-3d.h
    src/interfaces.h
    src/main.cpp
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} glad)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ls_vm src)
target_link_libraries(${PROJECT_NAME} ls_vm)


set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)