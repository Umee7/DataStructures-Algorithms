#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution {
public:
    int findMaxSum(int index, vector<int> &nums) {
        if(index >= nums.size() - 1) {
            return 0;
        }

        return max(nums[index] + findMaxSum(index + 2,  nums), findMaxSum(index + 1, nums));
    }

    int findMaxSum2(int index, vector<int> &nums) {
        if(index >= nums.size()) {
            return 0;
        }

        return max(nums[index] + findMaxSum2(index + 2,  nums), findMaxSum2(index + 1, nums));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);

        return max(findMaxSum(0, nums),  findMaxSum2(1, nums));
    }
};

// 2. Memoisation
class Solution {
public:

    int findMaxSum(int index, vector<int> &nums, vector<int> &dp) {
        if(index >= nums.size() - 1) {
            return 0;
        }

        if(dp[index] != -1) return dp[index];
        return dp[index] = max(nums[index] + findMaxSum(index + 2,  nums, dp), findMaxSum(index + 1, nums, dp));
    }

    int findMaxSum2(int index, vector<int> &nums, vector<int> &dp2) {
        if(index >= nums.size()) {
            return 0;
        }
        if(dp2[index] != -1) return dp2[index];
        return dp2[index] = max(nums[index] + findMaxSum2(index + 2,  nums, dp2), findMaxSum2(index + 1, nums, dp2));
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        vector<int> dp(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);

        return max(findMaxSum(0, nums, dp),  findMaxSum2(1, nums, dp2));
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> dp(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size() - 1; i++) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }

        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); i++) {
            dp2[i] = max(dp2[i-1], nums[i] + dp2[i-2]);
        }

        return max(dp[nums.size() - 2], dp2[nums.size() - 1]);
    }
};