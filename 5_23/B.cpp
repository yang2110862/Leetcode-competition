#include "header.h"

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (n - 1 > hour) return -1;
        int sum_len = 0;
        for (int i = 0; i < n; ++i) {
            sum_len += dist[i];
        }
        int min_speed = ceil(1.0 * sum_len / hour);
        for (int i = min_speed; ; ++i) {
            double curr_hour = 0;
            for (int j = 0; j < n - 1; ++j) {
                curr_hour += ceil(1.0 * dist[j] / min_speed);
            }
            curr_hour += 1.0 * dist[n - 1] / i;
            if (curr_hour <= hour) {
                return i;
            }
        }
        return -1;
    }
};
