#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int>& nums) {
            // The Bruteforce would be of Space Complexity - O(n!*n*log(n!))
            // Optimal Solution
            int pivot = 0;
            int rightGreater = 0;
            for(int i = nums.size() - 2; i >= 0; i--) {
                if(nums[i] < nums[i+1]) {
                    pivot = i;
                    break;
                }
            }
    
            for(int i = nums.size() - 1; i > pivot; i--) {
                if(nums[i] > nums[pivot]) {
                    rightGreater = i;
                    break;
                }
            }
    
            if(!rightGreater){
                reverse(nums.begin(), nums.end());
            } else {
                swap(nums[pivot], nums[rightGreater]);
                reverse(nums.begin() + pivot + 1, nums.end());
            }

            // Time Complexity - O(n) Space Complexity - O(1)
        }
    };