// 统计四种情况即可
#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int x;

unordered_map<string, int> op;

int main()
{
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        op[str]++;
    }
    x += op["++X"] + op["X++"];
    x -= op["--X"] + op["X--"];

    cout << x << endl;

    return 0;
}   