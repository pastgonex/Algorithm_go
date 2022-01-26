#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
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

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[n++] = nums[i];
            }
        }
        return n;
    }
};