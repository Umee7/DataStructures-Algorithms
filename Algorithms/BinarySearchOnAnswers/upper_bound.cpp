#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    int upperBound(vector<int> &nums, int key) {
        int low = 0, high = nums.size() - 1;
        int result = nums.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] > key) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};

int main() {
	Solution solution;
	vector<int> nums = {1,2,2,3};
    int key = 2;
    int result = solution.upperBound(nums, key);
    cout<<result;
}
