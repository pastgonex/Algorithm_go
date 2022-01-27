#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;

typedef struct ArrayList {
    int size, capacity;
    int *data;
}ArrayList;

// 初始
ArrayList init(int capacity) {
    ArrayList list;
    list.size = 0;
    list.capacity = capacity;
    list.data = (int*)malloc(sizeof(int) * capacity);
    return list;
}

// push back
void push_back(ArrayList *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
    list->data[list->size++] = value;
}

void pop_back(ArrayList *list) {
    list->size--;
    if (list->size < list->capacity * 0.25) {
        list->capacity /= 2;
        list->data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    }
}

void show(ArrayList list) {
    for (int i = 0; i < list.size; i++) {
        cout << list.data[i] << " ";
    }
    puts("");
}

int main() {
    ArrayList arrayList = init(5);
    int t = 5;
    while (t--) {
        push_back(&arrayList, t);
    }
    show(arrayList);
    t = 5;
    while (t--) {
        push_back(&arrayList,t);
    }
    show(arrayList);

    pop_back(&arrayList);
    show(arrayList);
}