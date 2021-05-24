#include "header.h"

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 10000005;
        int n = dist.size();
        while (l < r) {
            int mid = (l + r) / 2;
            double total = 0;
            for (int i = 0; i < n - 1; ++i) {
                total += ceil(1.0 * dist[i] / mid);
            }
            total += 1.0 * dist[n - 1] / mid;
            if (total <= hour) {    //相等的时候闭区间
                r = mid;
            } else {  //不等的时候开区间
                l = mid + 1;
            }
            if (l > 10000002) return -1;
        }
        return l;
    }
};