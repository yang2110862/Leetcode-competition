#include "header.h"

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pre;
        partial_sum(stones.begin(), stones.end(), back_inserter(pre));
        vector<int> dp(n);
        dp[n - 1] = pre[n - 1];
        for (int i = n - 2; i >= 1; --i) {
            dp[i] = max(pre[i] - dp[i + 1], dp[i + 1]);
        }
        return dp[1];
    }
};