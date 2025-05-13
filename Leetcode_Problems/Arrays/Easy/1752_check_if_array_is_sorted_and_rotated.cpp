#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        // My Bruteforce
        // int left = 0;
        // int right = 1;
        // int count = 0;
        // for(int i = 0; i<nums.size()-1; i++)
        // {
        //     if(nums[i]<=nums[i+1])
        //     {
        //         count++;
        //     }
        // }
        // if(count==nums.size()-1)
        // {
        //     return true;
        // }else {
        //     while(right<nums.size())
        // {   
        //     int low = left;
        //     vector<int> B;
        //     vector<int> temp;
        //     while(low<right)
        //     {
        //         temp.push_back(nums[low]);
        //         low++;
        //     }
        //     for(int i = right; i<nums.size();i++)
        //     {
        //         B.push_back(nums[i]);
        //     }
        //     for(int i =0; i<temp.size(); i++)
        //     {
        //         B.push_back(temp[i]);
        //     }
        //     int count = 0;
        //     for(int i = 0; i<B.size()-1; i++){
        //         if(B[i]<=B[i+1])
        //         {
        //             count++;
        //         }
        //     }
        //     if(count==nums.size()-1){
        //         return true;
        //     }
        //     right++;
        // }
        // return false;
        // }

        // Optimal
        int size = nums.size();
        int count = 1;
        for (int i = 1; i < 2 * size; i++) {
            if (nums[(i - 1) % size] <= nums[i % size]) {
                count++;
            } else {
                count = 1;
            }
            if (count == size)
                return true;
        }
        return size == 1;
    }  
};