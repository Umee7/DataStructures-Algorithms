#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // My Brute Force 
        // int size = nums.size();
        // if(size==0) return;
        // k = k % size;
        // vector<int> temp(size);
        // for(int i = 0; i < k; i++) {
        //     temp[i] = nums[size -k +i];
        // }

        // for(int i = 0; i < size - k;i++) {
        //     temp[k+i] = nums[i];
        // }
        
        // for(int i = 0; i < size; i++) {
        //     nums[i] = temp[i];
        // }
        // Time Complexity - 0(N) Space Complexity - 0(N)

        // Better Approach
        // int size = nums.size();
        // if(size==0) return;
        // k = k % size;
        // vector<int> temp(k);
        // for (int i = size - k; i < size; i++) {
        //     temp[i - size + k] = nums[i];
        // }

        // for (int i = size - k - 1; i >= 0; i--) {
        //     nums[i+k] = nums[i];
        // }

        // for(int i =0; i < k; i++) {
        //     nums[i] = temp[i];
        // }
        // Time Complexity - 0(N) Space Complexity - 0(k)

        // Optimal Approach
        int size = nums.size();
        if(size==0) return;
        k = k % size;
        reverse(nums.end() - k , nums.end());
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.begin(), nums.end());
        
    }
};