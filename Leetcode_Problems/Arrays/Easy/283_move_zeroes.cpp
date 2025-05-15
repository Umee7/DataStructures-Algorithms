#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    void moveZeroes(vector<int>& nums) {
        // Optimal solution
        int left = 0;
        for(int right = 0; right < nums.size(); right++) {
            if(nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};