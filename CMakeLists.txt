#// CMake 最低版本号要求
cmake_minimum_required (VERSION 3.16)
#// 项目信息
project (Demo3)
#// 查找当前目录下的所有源文件
#// 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

#// OpenCV
#//当有多个opencv版本时，可指定优先查找opencv的目录OpenCV_DIR
#set(OpenCV_DIR /opt/ros/kinetic/share/OpenCV-3.3.1-dev)
find_package(OpenCV 4.2 REQUIRED)

#// 添加include文件查找目录，这里把CMakeLists.txt所在目录添加了进去
include_directories(
        ${PROJECT_SOURCE_DIR}/
        ${OpenCV_INCLUDE_DIRS}
)
#// 指定生成目标
add_executable(Demo main.cpp)
#// 添加链接库
target_link_libraries(Demo
        ${OpenCV_LIBS}
        )