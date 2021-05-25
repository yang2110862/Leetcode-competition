#include "header.h"

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = box[m - j - 1][i];
            }
        }
        for (int i = 0; i < m; ++i) {
            int button = n - 1;
            for (int j = n - 1; j >= 0; --j) {
                if (res[j][i] == '*') {
                    button = j - 1;
                } else if (res[j][i] == '#') {
                    res[j][i] = res[button][i];
                    res[button--][i] = '#';
                }
            }
        }
        return res;
    }
};