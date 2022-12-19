# minimum cmake version required to build project
cmake_minimum_required(VERSION 3.10)

# set project name
set(PROJECTNAME "Main")
project(${PROJECTNAME} VERSION 1.0)

# define compiler standard
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

add_executable(TestSerial testSerial.cpp lib/src/Serial.cpp)       

add_executable(TestQueue testQueue.cpp)

add_executable(TestEventParser testEventParser.cpp)

add_executable(TestGetTime testGetTime.cpp)

add_executable(TestList testList.cpp)

add_executable(MeterStationHost "${PROJECT_SOURCE_DIR}/apps/computer/main.cpp" lib/src/Serial.cpp)
add_executable(MeterStationEmbd "${PROJECT_SOURCE_DIR}/apps/embedded/main.cpp" lib/src/Serial.cpp)

target_include_directories(TestSerial   PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )

target_include_directories(TestQueue    PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )
                                        
target_include_directories(TestEventParser  PUBLIC "${PROJECT_SOURCE_DIR}"
                                            "${PROJECT_SOURCE_DIR}/lib/include"
                                            )

target_include_directories(TestGetTime  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )

target_include_directories(TestList  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )

target_include_directories(MeterStationHost PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )

target_include_directories(MeterStationEmbd PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )