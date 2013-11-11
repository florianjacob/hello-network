cmake_minimum_required(VERSION 2.8.8)
project(hello_server)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Can be recuded in cmake 2.8.11, see http://qt-project.org/doc/qt-5.1/qtdoc/cmake-manual.html
# as long is using cmake <2.8.11, remember to adjust qt5_use_modules below
find_package(Qt5Network REQUIRED)

ADD_DEFINITIONS("-std=c++11")
add_executable(hello_server main.cpp server.cpp connection.cpp)
qt5_use_modules(hello_server Network)

