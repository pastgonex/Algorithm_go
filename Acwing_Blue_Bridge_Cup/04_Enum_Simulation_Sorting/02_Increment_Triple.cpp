//
// Created by Genes on 2020/9/14.
//
// 递增三元组

//优化版本
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int n, res;
int a[N], b[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    //读入完成

}

//暴力版本
//#include<iostream>
//
//using namespace std;
//
//const int N = 1e5 + 10;
//
//int n;
//int a[N], b[N], c[N];
//int res;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> b[i];
//    }
//    for (int i = 0; i < n; i++) {
//        cin >> c[i];
//    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            for (int k = 0; k < n; k++) {
//                if (a[i] < b[j] && b[j] < c[k]) {
//                    res++;
//                }
//            }
//        }
//    }
//    cout << res << endl;
//    return 0;
//}

