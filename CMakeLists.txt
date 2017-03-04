cmake_minimum_required(VERSION 2.8.11)
project(musicplayer)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

set(musicplayer_SRC
  src/main.cpp
  src/musicplayer.cpp
)

# Create code from a list of Qt designer ui files.
#set(CMAKE_AUTOUIC ON) # use this if you have CMake 3.x instead of the following
qt5_wrap_ui(musicplayer_SRC src/musicplayer.ui)

# Tell CMake to create the helloworld executable
add_executable(musicplayer ${musicplayer_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(musicplayer Qt5::Widgets)

# Install the executable
install(TARGETS musicplayer DESTINATION bin)
