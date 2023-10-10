cmake_minimum_required(VERSION 3.14) #CMake的最低版本为3.14

project(FGroundControl VERSION 0.1 LANGUAGES CXX) #指定项目名称、版本号和编程语言

set(CMAKE_AUTOUIC ON) #开启UIC编译，将窗口UI文件转换为标准Cpp程序
set(CMAKE_AUTOMOC ON) #开启元对象编译，将Qt Cpp头文件转化为标准Cpp程序
set(CMAKE_AUTORCC ON) #开启RCC编译，将资源文件转化为标准Cpp程序

set(CMAKE_CXX_STANDARD 11) #指定C++的标准为C++11
set(CMAKE_CXX_STANDARD_REQUIRED ON) #要求CMake强制使用这个标准

find_package(Qt5 REQUIRED COMPONENTS Core Quick WebEngine) #寻找Qt5的Core、Quick、WebEngine模块,找不到将报错（REQUIRED关键字）

#aux_source_directory(src PROJECT_SOURCES) #查找src目录中的所有源文件，并将它们存储在"PROJECT_SOURCES"变量中

#include_directories(src)
file(GLOB_RECURSE PROJECT_HEADERS "src/*.h")
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp")

#link_directories(
#    ${LIBS_PATH}/ffmpeg/lib
#)

add_executable(FGroundControl #创建一个名为"FGroundControl"的可执行文件
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    qml.qrc
)

set(LIBS_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs) #设置外部库的目录并作为变量"LIBS_PATH"

include_directories( #配置项目的包含目录
    ${LIBS_PATH}/mavlink
    ${LIBS_PATH}/mavlink/test
    ${LIBS_PATH}/ffmpeg/include
)

add_subdirectory(libs) #构建libs子目录中的库，libs文件夹下必须包含CMakeLists.txt文件

target_include_directories(FGroundControl PRIVATE include)

target_link_libraries(FGroundControl #指定了可执行文件依赖的Qt模块
    PRIVATE Qt5::Core Qt5::Quick Qt5::WebEngine
    ${LIBS_PATH}/ffmpeg/lib/libavcodec.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libavdevice.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libavfilter.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libavformat.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libavutil.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libpostproc.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libswresample.dll.a
    ${LIBS_PATH}/ffmpeg/lib/libswscale.dll.a
)

#set_target_properties(FGroundControl PROPERTIES
#    WIN32_EXECUTABLE TRUE
#)

#install(TARGETS FGroundControl
#    BUNDLE DESTINATION .
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#)

