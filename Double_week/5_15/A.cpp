#include "header.h"

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans;
        int n = s.size();
        istringstream word(s);
        string temp;
        while(word >> temp) {
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end(), [](string& a, string& b) {
            int m = a.size();
            int n = b.size();
            return a[m - 1] < b[n - 1];
        });
        string res;
        n = ans.size();
        for (int i = 0; i < n - 1; ++i) {
            res += ans[i].substr(0, ans[i].size() - 1);
            res += " ";
        }
        res += ans[n - 1].substr(0, ans[n - 1].size() - 1);
        return res;
    }
};
