#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const int N = 19;  // LL max: 9.22e18
const int P = 1e9 + 7;

int power10Mod7[N + 1];  // 10 ^ i % 7
int power10ModP[N + 1];  // 10 ^ i % P

struct Node {
    int s0, s1, s2;
} f[N + 1][10][7][7];  // number itself % 7, digit sum % 7


int mod(LL x, int y) {
    return (x % y + y) % y;
}

void init() {
    for (int i = 0; i <= 9; i++) {
        if (i == 7) {
            continue;
        }
        auto &v = f[1][i][i % 7][i % 7];
        v.s0++;
        v.s1 += i;
        v.s2 += i * i;
    }

    LL power = 10;  // 10 ^ (i - 1)
    for (int i = 2; i <= N; i++, power *= 10) {
        for (int j = 0; j <= 9; j++) {  // cur pos
            if (j == 7) {
                continue;
            }
            for (int a = 0; a < 7; a++) {
                for (int b = 0; b < 7; b++) {
                    for (int k = 0; k <= 9; k++) {  // next pos
                        if (k == 7) {
                            continue;
                        }
                        auto &v1 = f[i][j][a][b];
                        auto &v2 = f[i - 1][k][mod(a - j * power, 7)][mod(b - j, 7)];
                        // 1 + 1 + ... + 1  // t times
                        // = t
                        v1.s0 += v2.s0 % P;
                        // jA1 + jA2 + ... + jAt
                        // = (j * 10 ^ (i - 1) + A1) + ...  // // think of f[i][j]
                        // = j * 10 ^ (i - 1) * t + (A1 + A2 + ... + At)
                        v1.s1 += (j * (power % P) % P * v2.s0 + v2.s1) % P;
                        // (jA1) ^ 2 + (jA2) ^ 2 + ... + (jAt) ^ 2
                        // = (j * 10 ^ (i - 1) + A1) ^ 2 + ...
                        // = (j * j * 10 ^ (i - 1) * 10 ^ (i - 1) + 2 * j * 10 ^ (i - 1) * A1 + A1 * A1) + ...
                        // = (j * j * 10 ^ (i - 1) * 10 ^ (i - 1) * t +
                        //    2 * j * 10 ^ (i - 1) * (A1 + A2 + ... + At) +
                        //    (A1 * A1 + A2 * A2 + ... + At * At)
                        v1.s2 += (j * j * (power % P) % P * (power % P) % P * v2.s0 + 2 * j * power % P * v2.s1 +
                                  v2.s2) % P;

                        v1.s0 %= P;
                        v1.s1 %= P;
                        v1.s2 %= P;
                    }
                }
            }
        }
    }

    power10Mod7[0] = 1;
    for (int i = 1; i <= N; i++) {
        power10Mod7[i] = power10Mod7[i - 1] * 10 % 7;
    }

    power10ModP[0] = 1;
    for (int i = 1; i <= N; i++) {
        power10ModP[i] = power10ModP[i - 1] * 10ll % P;
    }
}

Node sum(int i, int j, int a, int b) {  // encapsulate a sum operation for certain i, j
    int s0 = 0, s1 = 0, s2 = 0;
    for (int x = 0; x < 7; x++) {
        for (int y = 0; y < 7; y++) {
            if (x != a && y != b) {  // mod 7 not 0
                auto v = f[i][j][x][y];
                s0 = (s0 + v.s0) % P;
                s1 = (s1 + v.s1) % P;
                s2 = (s2 + v.s2) % P;
            }
        }
    }
    return {s0, s1, s2};
}

int dp(LL n) {
    if (!n) {
        return 0;
    }
    LL x = n;
    vector<int> nums;
    while (x) {
        nums.push_back(x % 10);
        x /= 10;
    }

    int res = 0;
    LL last_a = 0, last_b = 0;
    int i = nums.size() - 1;
    while (i >= 0) {
        int x = nums[i];
        for (int j = 0; j < x; j++) {
            if (j == 7) {
                continue;
            }
            int a = mod(-last_a * power10Mod7[i + 1], 7);
            int b = mod(-last_b, 7);
            auto v = sum(i + 1, j, a, b);
            // (last_ajA1) ^ 2 + (last_ajA2) ^ 2 + ... + (last_ajAt) ^ 2
            // = (last_a * 10 ^ (i + 1) + jA1) ^ 2 + ...
            // = last_a * last_a * 10 ^ (i + 1) * 10 ^ (i + 1) + 2 * last_a * 10 ^ (i + 1) * A1 + A1 * A1
            // = last_a * last_a * 10 ^ (i + 1) * 10 ^ (i + 1) * t +
            //   2 * last_a * 10 ^ (i + 1) * (A1 + A2 + ... + At) +
            //   (A1 * A1 + A2 * A2 + ... + At * At)
            res = (res +
                   (last_a % P) * (last_a % P) % P * power10ModP[i + 1] % P * power10ModP[i + 1] % P * v.s0 % P +
                   2 * last_a % P * power10ModP[i + 1] % P * v.s1 +
                   v.s2) % P;
        }

        if (x == 7) {
            break;
        }
        last_a = last_a * 10 + x;
        last_b += x;

        i--;
    }

    if (i == -1 && last_a % 7 && last_b % 7) {
        res = (res + (n % P) * (n % P)) % P;
    }

    return res;
}

LL solve(LL l, LL r) {
    return mod(dp(r) - dp(l - 1), P);
}

int main() {
    int T;
    cin >> T;

    init();

    while (T--) {
        LL l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }

    return 0;
}