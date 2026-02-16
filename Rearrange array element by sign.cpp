#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    int posIndex = 0;  // even index
    int negIndex = 1;  // odd index

    for(int i = 0; i < n; i++) {
        if(nums[i] >= 0) {
            result[posIndex] = nums[i];
            posIndex += 2;
        }
        else {
            result[negIndex] = nums[i];
            negIndex += 2;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, -4, -5, 3, -6};
    
    vector<int> ans = rearrangeArray(nums);

    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}
