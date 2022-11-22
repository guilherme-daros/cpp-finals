# minimum cmake version required to build project
cmake_minimum_required(VERSION 3.10)

# set project name
set(PROJECTNAME "Main")
project(${PROJECTNAME} VERSION 1.0)

# define compiler standard
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)


add_executable(${PROJECT_NAME}
                main.cpp
                )

add_executable(TestSerial
                test.cpp
                lib/src/Serial.cpp
                )       



target_include_directories(${PROJECTNAME}  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )

target_include_directories(TestSerial  PUBLIC "${PROJECT_SOURCE_DIR}"
                                        "${PROJECT_SOURCE_DIR}/lib/include"
                                        )