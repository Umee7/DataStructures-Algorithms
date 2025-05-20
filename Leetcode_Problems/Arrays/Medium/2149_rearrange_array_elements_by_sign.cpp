#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        vector<int> rearrangeArray(vector<int> &nums) {
            // My Bruteforce
            // vector<int> resultArray(nums.size());
            // vector<int> positiveArray;
            // vector<int> negativeArray; 
            // for(int i = 0; i < nums.size(); i++) {
            //     if(nums[i] >= 0) {
            //         positiveArray.push_back(nums[i]);
            //     } else {
            //         negativeArray.push_back(nums[i]);
            //     }
            // }
            // int left = 0, right = 0;
            // for(int i = 0; i < resultArray.size(); i++) {
            //     if(i % 2 == 0) {
            //         resultArray[i] = positiveArray[right];
            //         right++;
            //     } else {
            //         resultArray[i] = negativeArray[left];
            //         left++;
            //     }
            // }
            // return resultArray;

            // Time Complexity - O(n) Space Complexity - O(n)

            // My Optimal
            vector<int> resultArray(nums.size());
            int negativeElement = 0;
            int positiveElement = 0;

            for (int i = 0; i < resultArray.size(); i++) {
                while (positiveElement < nums.size() && nums[positiveElement] < 0) {
                    positiveElement++;
                }

                while (negativeElement < nums.size() && nums[negativeElement] > 0) {
                    negativeElement++;
                }
                if (i % 2 == 0) {
                    resultArray[i] = nums[positiveElement];
                    positiveElement++;
                } else {
                    resultArray[i] = nums[negativeElement];
                    negativeElement++;
                }
            }

            return resultArray;

            // Time Complexity - O(n) Space Complexity O(n);
        }
    };