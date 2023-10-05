cmake_minimum_required(VERSION 3.14) #CMake的最低版本为3.14

project(FGroundControl VERSION 0.1 LANGUAGES CXX) #指定项目名称、版本号和编程语言

set(CMAKE_AUTOUIC ON) #开启UIC编译，将窗口UI文件转换为标准Cpp程序
set(CMAKE_AUTOMOC ON) #开启元对象编译，将Qt Cpp头文件转化为标准Cpp程序
set(CMAKE_AUTORCC ON) #开启RCC编译，将资源文件转化为标准Cpp程序

set(CMAKE_CXX_STANDARD 11) #指定C++的标准为C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON) #要求CMake强制使用这个标准

find_package(Qt5 REQUIRED COMPONENTS Core Quick) #找到Qt5的Core、Quick模块

set(PROJECT_SOURCES #列出项目的源文件
        main.cpp
        qml.qrc
)

add_executable(FGroundControl #创建一个名为"FGroundControl"的可执行文件
    ${PROJECT_SOURCES}
)

include_directories( #配置项目的包含目录
    libs/mavlink
    libs/mavlink/test
)
add_subdirectory(libs) #构建libs子目录中的库，libs文件夹下必须包含CMakeLists.txt文件

target_link_libraries(FGroundControl #指定了可执行文件依赖的Qt模块
    PRIVATE Qt5::Core Qt5::Quick)

set_target_properties(FGroundControl PROPERTIES
    WIN32_EXECUTABLE TRUE
)

install(TARGETS FGroundControl
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

