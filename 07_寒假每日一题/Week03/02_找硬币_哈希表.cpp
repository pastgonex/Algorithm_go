/*
 * Project: Week3
 * File Created:Tuesday, January 19th 2021, 8:33:06 pm
 * Author: Bug-Free
 * Problem:AcWing 1532. 找硬币 哈希表
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

using namespace std;

const int N = 1e5 + 10;

int n, m;

int main() {
  cin >> n >> m;
  unordered_set<int> hash;

  int v1 = 1e4, v2;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a;
    b = m - a;
    // 如果hash表中存在b
    if (hash.count(b)) {
      hash.insert(a);
      if (a > b) {
        swap(a, b);
      }
      if (a < v1) {
        v1 = a, v2 = b;
      }
    } else {
      hash.insert(a);
    }
  }
  if (v1 == 1e4) {
    puts("No Solution");
  } else {
    cout << v1 << " " << v2 << endl;
  }
  return 0;
}
