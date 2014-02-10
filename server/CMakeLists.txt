project(hello_server)
cmake_minimum_required(VERSION 2.8.11)

# See http://qt-project.org/doc/qt-5.1/qtdoc/cmake-manual.html
find_package(Qt5Network REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

ADD_DEFINITIONS("-std=c++11")

set(hello_server_src
	main.cpp
	server.cpp
	connection.cpp
	)

add_executable(hello_server ${hello_server_src})
target_link_libraries(hello_server Qt5::Network)
