//
// Created by Genes on 2020/9/26.
//
// 航班时间
//
#include<iostream>
#include <string>

using namespace std;

int get_time() {
    string line;
    getline(cin, line);
    if (line.back() != ')') line += " (+0)"; // 时间统一
    int h1, m1, s1, h2, m2, s2, d;
    sscanf(line.c_str(), "%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d); //从字符串中按照这个格式读出来
    //转换成秒s
    return 3600 * h2 + 60 * m2 + s2 - 3600 * h1 - 60 * m1 - s1 + d * 24 * 3600;
}

int main() {
    int t;
    scanf("%d", &t);
    getchar(); //去除第一行的空格, 就是t后面的空格,以免后面getline出错
    while (t--) {
        int time = (get_time() + get_time()) / 2;
        int hour = time / 3600, minute = time % 3600 / 60, second = time % 60;
        printf("%02d:%02d:%02d\n", hour, minute, second); //不足2位则补上0
    }
    return 0;
}
