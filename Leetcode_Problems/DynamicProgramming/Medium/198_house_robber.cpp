#include<bits/stdc++.h>
using namespace std;

// 1. Recursive solution
class Solution {
public:   
    int MAX_AMOUNT = 0;
    void findMaxAmount(int index, int currentSum, vector<int> &nums) {
        if(index >= nums.size()) {
            MAX_AMOUNT = max(MAX_AMOUNT, currentSum);
            return;
        }    

        // Pick 
        findMaxAmount(index + 2, currentSum + nums[index], nums);
        // Not Pick 
        findMaxAmount(index + 1, currentSum, nums);
    }

    int houseRobber(vector<int> &nums) {
        findMaxAmount(0, 0, nums);
        return MAX_AMOUNT;
    }
};

// 2. Memoization
class Solution {
public:
    int findMaxAmount(int index,vector<int>& nums, vector<int> &dp) {
        if (index >= nums.size()) {
           return 0;
        }
        if (dp[index] != -1)
            return dp[index];
        return dp[index] = max(nums[index] + findMaxAmount(index + 2, nums, dp),findMaxAmount(index + 1, nums, dp));
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return findMaxAmount(0, nums, dp);
    }
};

// 3. tabulation
class Solution {
public:

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[nums.size() - 1];
    }
};