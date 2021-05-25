#include "header.h"

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int flag = 0; //1往memory1放，2往memory2放；
        if (memory1 >= memory2) flag = 1;
        int remain1 = memory1, remain2 = memory2;
        int second = 0;
        int bit = 1;
        int crash_time;
        while(1) {
            ++second;
            if (remain1 >= remain2) {
                flag = 1;
            } else {
                flag = 2;
            }
            if (flag == 1) {
                if (bit > remain1) {
                    crash_time = second;
                    break;
                }
                remain1 -= bit;
            } else {
                if (bit > remain2) {
                    crash_time = second;
                    break;
                }
                remain2 -= bit;
            }
            ++bit; 
        }
        vector<int> ans;
        ans.push_back(crash_time);
        ans.push_back(remain1);
        ans.push_back(remain2);
        return ans;
    }
};

int main() {
    Solution test;
    int memory1 = 2, memory2 = 2;
    cout << test.memLeak(memory1, memory2)[1];
}