// sort
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string str;
vector<int> numbers;

int main()
{
    cin >> str;
    for (auto c : str) {
        if ('0' <= c && c <= '9') {
            numbers.push_back(c - '0');
        }
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i];
        if (i != numbers.size() - 1) {
            cout << "+";
        }
    }

    cout << endl;

    return 0;
}