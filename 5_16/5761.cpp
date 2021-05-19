#include "header.h"

class FindSumPairs {
private:
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (auto y : nums2) {
            ++cnt[y];
        }
    }
    
    void add(int index, int val) {
        --cnt[nums2[index]];
        nums2[index] += val;
        ++cnt[nums2[index]];
    }
    
    int count(int tot) {
        int ans = 0;
        for (auto x : nums1) {
            int res = tot - x;
            if (cnt.count(res)) {
                ans += cnt[res];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums1{1,1,2,2,2,3};
    vector<int> nums2{1,4,5,2,5,4};
    FindSumPairs test(nums1, nums2);
    cout << test.count(7);
    return 0;
}