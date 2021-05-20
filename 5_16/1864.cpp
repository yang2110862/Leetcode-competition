#include "header.h"
 //改天再写
class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if (n == 1) {
            return 0;
        }
        int cnt1 = 0, cnt0 = 0;
        int num0 = 0;
        if (n % 2 == 0) {
            for (int i = 0; i < n; ++i) {
                if(i % 2 == 0 &&  s[i] == '0') {
                    cnt1++;
                }
                if(i % 2 == 0 && s[i] == '1') {
                    cnt0++;
                }
                if (s[i] == '0') {
                    ++num0;
                }
            }
            if (abs((n - num0) - num0) <= 1) {
                return min(cnt1, cnt0);
            } else {
                return -1;
            }            
        } else {
            for (int i = 0; i < n; ++i) {
                if(i % 2 == 0 &&  s[i] == '0') {
                    cnt1++;
                }
                if(i % 2 == 0 && s[i] == '1') {
                    cnt0++;
                }
                if (s[i] == '0') {
                    ++num0;
                }
            }
        }
    }
};


int main() {
    Solution test;
    string s = "100";
    cout << test.minSwaps(s);
    return 0;
}
