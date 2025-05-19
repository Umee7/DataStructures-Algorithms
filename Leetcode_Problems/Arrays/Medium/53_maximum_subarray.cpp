#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // My Optimal 
        int maxSum = nums[0]; 
        int currentSum = nums[0];
        if(nums.size() < 2) return maxSum;
        for(int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;

        // Time Complexity - O(n) Space Complexity - O(1)
    }
};