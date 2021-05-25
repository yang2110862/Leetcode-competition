#include "header.h"

class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int beg = 0;
            while(beg < n) {
                int div = nums[beg] / nums[i];
                int tar = (div + 1) * nums[i];
                int ed = lower_bound(nums.begin() + beg, nums.end(), tar) - nums.begin();
                res += (ed - beg) * div;
                beg = ed;
            }
        }
        return (int)(res % 1000000007);
    }
};