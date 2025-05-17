#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // My Brute Force
        // for(int i = 0; i < nums.size(); i++) {
        //     for(int j = i + 1; j < nums.size(); j++) {
        //         if((nums[i] + nums[j]) == target) {
        //             return {i, j};
        //         } 
        //     }
        // }
        // return {-1, -1};

        // Time Complexity - 0(n) Space Complexity - 0(1)

        // My Optimal Solution (without HashTable) 
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int left = 0; int right = nums.size() - 1;
        int leftNumber = -1;
        int rightNumber = -1;
        while (left < right) {
            if ((temp[left] + temp[right]) == target) {
                leftNumber = temp[left];
                rightNumber = temp[right];
                break;
            } else if ((temp[left] + temp[right]) < target) {
                left++;
            } else {
                right--;
            }
        }

        int index1 = -1, index2 = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == leftNumber && index1 == -1) {
                index1 = i;
            } else if (nums[i] == rightNumber && index2 == -1) {
                index2 = i;
            }
        }
        return {index1, index2}; 

        // Time Complexity - O(n log n) Space Complexity - O(n)
        // Can solve it in O(n) time complexity by using hashtable
    }
};