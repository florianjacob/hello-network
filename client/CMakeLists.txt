cmake_minimum_required(VERSION 2.8.8)
project(hello_client)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Can be recuded in cmake 2.8.11, see http://qt-project.org/doc/qt-5.1/qtdoc/cmake-manual.html
# as long is using cmake <2.8.11, remember to adjust qt5_use_modules below
find_package(Qt5Network REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Qt5Widgets REQUIRED)

ADD_DEFINITIONS("-std=c++11")
add_executable(hello_client main.cpp client.cpp)
qt5_use_modules(hello_client Network Quick Widgets)

# copy the qml file over to the binary dir, to be able to run the binary straight away
file(COPY client.qml DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )

