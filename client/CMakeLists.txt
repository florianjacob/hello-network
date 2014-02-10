project(hello_client)
cmake_minimum_required(VERSION 2.8.11)

# See http://qt-project.org/doc/qt-5.1/qtdoc/cmake-manual.html
find_package(Qt5Network REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)


ADD_DEFINITIONS("-std=c++11")

set(hello_client_src
	main.cpp
	client.cpp
	)

set(hello_client_qrc
	qmlfiles.qrc
	)

qt5_add_resources(hello_client_wrapped_qrc ${hello_client_qrc})

add_executable(hello_client ${hello_client_src} ${hello_client_wrapped_qrc})
target_link_libraries(hello_client Qt5::Network Qt5::Quick Qt5::Widgets)

