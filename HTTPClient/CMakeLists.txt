cmake_minimum_required(VERSION 3.5)
project(MyMqttProject)

#isntall conan
execute_process(
   COMMAND conan install ${CMAKE_SOURCE_DIR} --build missing
   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

#Include Conan-generated CMake configuration
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()
#Append configure for CMAKE_PREFIX_PATH

add_executable(my_mqtt_app main.cpp network_lib/HttpClient.cpp)

include_directories(${CMAKE_SOURCE_DIR}/network_lib)

target_link_libraries(my_mqtt_app ${ActiveMQ_LIBRARIES})
include_directories(${ActiveMQ_INCLUDE_DIRS})

find_package(Boost 1.74.0 REQUIRED)
target_link_libraries(my_mqtt_app Boost::headers)

find_package(OpenSSL REQUIRED)
target_link_libraries(my_mqtt_app OpenSSL::Crypto OpenSSL::SSL) 
