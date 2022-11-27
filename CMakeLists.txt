# minimum cmake version required to build project
cmake_minimum_required(VERSION 3.10)

# set project name
set(PROJECTNAME "Main")
project(${PROJECTNAME} VERSION 1.0)

# define compiler standard
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_executable(Main
                main.cpp
                )

add_executable(TestSerial
                testSerial.cpp
                lib/src/Serial.cpp
                )       

add_executable(TestQueue
                testQueue.cpp)

target_include_directories(Main  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )

target_include_directories(TestSerial  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )
target_include_directories(TestQueue  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )
                                        