cmake_minimum_required(VERSION 2.8.3)
project(transforms)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    tf
    message_generation
    robot_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES transforms
   CATKIN_DEPENDS roscpp robot_msgs
#  DEPENDS system_lib
)

include_directories(include ${catkin_INCLUDE_DIRS})

## Declare a cpp executable
add_executable(sensor1_tf_node src/ir1_tf_broadcaster.cpp)
add_executable(sensor2_tf_node src/ir2_tf_broadcaster.cpp)
add_executable(sensor3_tf_node src/ir3_tf_broadcaster.cpp)
add_executable(sensor4_tf_node src/ir4_tf_broadcaster.cpp)
add_executable(map_robot_tf_node src/map_robot_tf.cpp)
add_executable(camera_tf_node src/camera_tf_broadcaster.cpp)
add_executable(ir_transform_node src/ir_transform.cpp)

## Specify libraries to link a library or executable target against
target_link_libraries(sensor1_tf_node ${catkin_LIBRARIES})
target_link_libraries(sensor2_tf_node ${catkin_LIBRARIES})
target_link_libraries(sensor3_tf_node ${catkin_LIBRARIES})
target_link_libraries(sensor4_tf_node ${catkin_LIBRARIES})
target_link_libraries(map_robot_tf_node ${catkin_LIBRARIES})
target_link_libraries(camera_tf_node ${catkin_LIBRARIES})
target_link_libraries(ir_transform_node ${catkin_LIBRARIES})
