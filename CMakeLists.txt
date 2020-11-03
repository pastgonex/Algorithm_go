cmake_minimum_required(VERSION 3.17)
project(Algorithm)
#
set(CMAKE_CXX_STANDARD 11)

# 遍历项目根目录下所有的 .cpp 文件
file(GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message(\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()

#cmake_minimum_required(VERSION 3.17)
#project(Algorithm)
##
#set(CMAKE_CXX_STANDARD 11)
#
## 遍历项目根目录下所有的 .cpp 文件
#file (GLOB_RECURSE files *.cpp)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file})
#    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()
#
## 参考网址: https://zhuanlan.zhihu.com/p/157646534
##  官方最优