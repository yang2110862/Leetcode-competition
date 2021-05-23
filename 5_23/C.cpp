#include "header.h"

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> dp(n), pre(n);
        dp[0] = 1;
        for (int i = 0; i < minJump; ++i) {
            pre[i] = 1;
        }
        for (int i = minJump; i < n; ++i) {
            int left = i - maxJump, right = i - minJump;
            if (s[i] == '0') {
                int total = pre[right] - (left <= 0 ? 0 : pre[left - 1]);
                if (total >= 1) dp[i] = 1;
            }
            pre[i] = pre[i - 1] + dp[i];
        }
        return dp[n - 1];
    }
};