#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int findBeautifulSubsets(int index, int k, vector<int> &temp, vector<int> nums) {
        // Base Case
        if(index == nums.size()) {
            return 1;
        }

        // pick case
        int pick = 0;
        if((find(temp.begin(), temp.end(), nums[index] + k) == temp.end()) && (find(temp.begin(), temp.end(), nums[index] - k) == temp.end())) {
            temp.push_back(nums[index]);
            pick = findBeautifulSubsets(index + 1, k, temp, nums);
            // Backtrack
            temp.pop_back();
        }

        int notPick = 0;
        // Not pick case
        notPick = findBeautifulSubsets(index + 1, k, temp, nums);

        return pick + notPick;

    };

    int beautifulSubsets(vector<int> &nums, int k) {
        vector<int> temp;
        return findBeautifulSubsets(0, k, temp, nums) - 1;
    }
};