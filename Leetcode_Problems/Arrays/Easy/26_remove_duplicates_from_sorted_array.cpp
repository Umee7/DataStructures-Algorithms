#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;
        while (right < nums.size()) {
            if (nums[right] != nums[left]) {
                nums[left + 1] = nums[right];
                left++;
                right++;
            } else {
                right++;
            }
        }
        return left + 1;
    }
};