#include <bits/stdc++.h>
using namespace std;

int longestSubarraySumK(vector<int>& arr, int k) {
    unordered_map<int, int> mp;  
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        // Case 1: subarray from start
        if (sum == k) {
            maxLen = i + 1;
        }

        // Case 2: sum - k exists
        if (mp.find(sum - k) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum - k]);
        }

        // Store prefix sum only first time
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, -2, 5};
    int k = 6;

    cout << longestSubarraySumK(arr, k);
    return 0;
}
