#include "header.h"


class Solution {
private:
    static const int mod = 1000000000 + 7;
public:
    int rearrangeSticks(int n, int k) {
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j - 1] % mod + (i - 1) * dp[i - 1][j] % mod;
            }
        }
        return dp[n][k] % mod;
    }
};
// 2-dim to two 1-dim
class Solution {
private:
    static constexpr int mod = 1000000007;
    
public:
    int rearrangeSticks(int n, int k) {
        vector<int> f(k + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<int> g(k + 1);
            for (int j = 1; j <= k; ++j) {
                g[j] = ((long long)f[j] * (i - 1) % mod + f[j - 1]) % mod;
            }
            f = move(g);
        }
        return f[k];
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/solution/qia-you-k-gen-mu-gun-ke-yi-kan-dao-de-pa-0c3g/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。