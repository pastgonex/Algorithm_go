#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1, n = nums.size();
        if (n == 0) return 0;
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && nums[i] == nums[j]) j++;
            if (j >= n) break;
            nums[cnt++] = nums[j];
            i = j;
        }
        return cnt;
    }
};