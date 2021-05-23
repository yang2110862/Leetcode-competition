#include "header.h"

class Solution {
public:
    bool checkZeroOnes(string s) {
        int n = s.size();
        vector<int> dp1(n + 1, 0);
        vector<int> dp0(n + 1, 0);
        dp1[0] = 0;
        dp0[0] = 0;
        int max1 = 0;
        int max0 = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '0') {
                dp0[i] = dp0[i - 1] + 1;
                dp1[i] = 0;
            } else {
                dp1[i] = dp1[i - 1] + 1;
                dp0[i] = 0;
            }
            max1 = max(max1, dp1[i]);
            max0 = max(max0, dp0[i]);
        }
        if (max1 > max0) {
            return true;
        } else {
            return false;
        }
    }
};