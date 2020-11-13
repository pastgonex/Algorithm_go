//
// Created by Genes on 2020/11/6.
//
// 转移图算法

#include<iostream>

using namespace std;

int main() {
    char c = getchar();
    switch (c) {
        case '<': {
            c = getchar();
            switch (c) {
                case '=': {
                    printf("<=\n");
                    break;
                }
                case '>': {
                    printf("<>\n");
                    break;
                }
                default: {
                    printf("rollback, <\n");
                }
            }
            break;
        }
        case '=': {
            printf("=\n");
            break;
        }
        case '>': {
            c = getchar();
            switch (c) {
                case '=': {
                    printf(">=\n");
                    break;
                }
                default: {
                    printf("rollback, >\n");
                }
            }
        }
    }
    return 0;
}
