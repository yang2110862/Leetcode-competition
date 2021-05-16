#include "header.h"
//用二进制表示序列的子集
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 1; i < (1 << n); ++i) {
            int sub_sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sub_sum = sub_sum ^ nums[j];
                }
            }
            sum += sub_sum;
        }
        return sum;
    }
};  