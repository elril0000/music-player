cmake_minimum_required(VERSION 2.8.11)
project(music-player)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(LIBRARY_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
set (CMAKE_CXX_STANDARD 14)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -pedantic -Werror -Wextra)
elseif (GNU)
  target_compile_definitions(${PROJECT_NAME} PUBLIC -Wsuggest-override -Wmain)
elseif (MSVC)
 # using Visual Studio C++
endif()

if(UNIX)
	IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
		SET(OPERATINGSYSTEM Linux)
	ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
elseif(WIN32)
	set(OPERATINGSYSTEM Win32)
	
endif()

configure_file(
  "${PROJECT_SOURCE_DIR}/src/config.hpp.in"
  "${PROJECT_SOURCE_DIR}/src/config.hpp"
)

# Find the QtWidgets library
find_package(Qt5 REQUIRED Core Multimedia COMPONENTS Widgets MultimediaWidgets)

file(GLOB SRCS src/*.cpp)

# Tell CMake to create the helloworld executable
add_executable(${PROJECT_NAME} ${SRCS})

# Use the Widgets module from Qt 5.
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)

# Install the executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
