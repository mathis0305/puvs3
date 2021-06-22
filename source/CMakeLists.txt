add_executable(example example.cpp)

target_link_libraries(example ${FRAMEWORK_NAME} ${LIBRARIES})
add_dependencies(example glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS example DESTINATION .)

add_executable(raytracer raytracer.cpp)

target_link_libraries(raytracer ${FRAMEWORK_NAME} ${LIBRARIES}
  glfw
  ${GLFW_LIBRARIES}
  )
add_dependencies(raytracer glfw ${FRAMEWORK_NAME} ${COPY_BINARY})

install(TARGETS raytracer DESTINATION .)

# Build tests
add_executable(tests
  tests.cpp
  ../framework/shape.cpp
  ../framework/shape.hpp
  ../framework/sphere.hpp
  ../framework/sphere.cpp
  ../framework/box.hpp
  ../framework/box.cpp
  ../framework/ray.cpp
  ../framework/ray.hpp
  ../framework/hitpoint.cpp
  ../framework/hitpoint.hpp
  )
target_link_libraries(tests
  ${GLFW_LIBRARIES}
  )

