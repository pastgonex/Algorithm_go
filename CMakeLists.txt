cmake_minimum_required(VERSION 3.17)
project(Algorithm)
#
set(CMAKE_CXX_STANDARD 11)

# 遍历项目根目录下所有的 .cpp 文件
file(GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file} Advanced_Guide_to_Algorithmic_Competitions/01_Basic_Algorithm/0x04_Dichotomy/02_Special_Sort.cpp Acwing_Basic_Algorithm_Course/01_Basic_Algorithm/04_High_Precision/01_High_Precision_addition.cpp Acwing_Basic_Algorithm_Course/01_Basic_Algorithm/04_High_Precision/02_High_Precision_subtraction.cpp)
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