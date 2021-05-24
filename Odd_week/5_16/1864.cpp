#include "header.h"

class Solution {
private:
    int num1;
    int num0;
public:
    int minSwaps(string s) {
        int len = s.size();
        for (auto c : s) {
            if (c == '1') ++num1;
            else ++num0;
        }
        int gap = num1 - num0;
        if (abs(gap) > 1) return -1;
        int ans = 0;
        if (gap == 0) {
            int error_1first = 0;
            int error_0first = 0;
            for (int i = 0; i < len; i += 2) {         //010101
                if ((i & 1) == 0) {
                    if (s[i] == '1') ++error_0first;
                }
            }
            for (int i = 0; i < len; i += 2) {         //101010
                if ((i & 1) == 0) {
                    if (s[i] == '0') ++error_1first;
                }
            }
            ans = min(error_0first, error_1first);
        } else if (gap == -1) { //0first
            int error_0 = 0;
            for (int i = 0; i < len; i += 2) {         //0101010
                if ((i & 1) == 0) {
                    if (s[i] == '1') ++error_0;
                }
            }
            ans = error_0;
        } else {   // 1first
            int error_1 = 0;
            for (int i = 0; i < len; i += 2) {         //1010101
                if ((i & 1) == 0) {
                    if (s[i] == '0') ++error_1;
                }
            }
            ans = error_1;
        }
        return ans;
    }
};

int main() {
    Solution test;
    string s = "0010111";
    cout << test.minSwaps(s);
    return 0;
}