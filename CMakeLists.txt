cmake_minimum_required(VERSION 2.8.3)
project(arena_unifei)

find_package(catkin REQUIRED COMPONENTS
	actionlib
	actionlib_msgs
	genmsg
	geometry_msgs
	message_generation
	nav_msgs
	robotino_node
	roscpp
	std_msgs
	tf
	)

find_package(Boost REQUIRED COMPONENTS system)

add_action_files(
	DIRECTORY action
	FILES 
	Align.action 
	Follow.action
	Grab.action
	Move.action
	Rotate.action 
	Store.action
	Translate.action 
	)

generate_messages(
	DEPENDENCIES
	actionlib_msgs
	std_msgs
	)

catkin_package(
	CATKIN_DEPENDS 
	actionlib_msgs
	)

include_directories(include ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

add_executable(arena_unifei_node 
	src/arena_unifei_node.cpp
	src/robots/Robot.cpp
	src/robots/Pioneer.cpp
	src/robots/Festo.cpp
	src/robots/AmigoBot.cpp
	src/robots/P3_DX.cpp
	src/robots/Robotino.cpp
	src/arenas/LRO.cpp
	)

target_link_libraries(arena_unifei_node
   	${catkin_LIBRARIES}
)

add_dependencies(arena_unifei_node 
	${catkin_EXPORTED_TARGETS}
	)
