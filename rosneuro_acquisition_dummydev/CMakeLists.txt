cmake_minimum_required(VERSION 2.8.3)
project(rosneuro_acquisition_dummydev)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(catkin REQUIRED COMPONENTS 
			 roscpp 
			 std_msgs
			 pluginlib
			 rosneuro_data
			 rosneuro_msgs)
find_package(rosneuro_acquisition 1.0.0 REQUIRED)

find_package(PkgConfig)

catkin_package(
  INCLUDE_DIRS 
	include
  LIBRARIES 
	${PROJECT_NAME}
  CATKIN_DEPENDS
  	roscpp
	std_msgs
	pluginlib
	rosneuro_data
	rosneuro_msgs
	rosneuro_acquisition

  DEPENDS
)


###########
## Build ##
###########

include_directories(${catkin_INCLUDE_DIRS}
					${rosneuro_acquisition_INCLUDE_DIRS}
					include
)

add_library(${PROJECT_NAME} 
			src/DummyDevice.cpp
)

target_link_libraries(${PROJECT_NAME} 
					  ${catkin_LIBRARIES}
					  ${rosneuro_acquisition_LIBRARIES}
)

add_dependencies(${PROJECT_NAME} 
				 ${catkin_EXPORTED_TARGETS}
)

#################
## Executables ##
#################

