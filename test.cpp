#include "header.h" 

int main() {
    vector<int> arr{1,2,3,4,6,7,8,9};
    int ans = upper_bound(arr.begin(), arr.end(), 9) - arr.begin();
    cout << ans;
    return 0;
}