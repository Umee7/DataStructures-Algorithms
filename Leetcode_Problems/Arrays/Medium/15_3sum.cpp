#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // Bruteforce - use 3 loops O(n^3) (Doesn't pass all test cases)
            //Optimal Solution
            vector<vector<int>> resultArray;
            sort(nums.begin(), nums.end());
            int left = 0;
            for (int left = 0; left < nums.size() - 2; left++) {
                if(left > 0 && nums[left] == nums[left-1]){
                 continue;
                };
                int current = left + 1;
                int right = nums.size() - 1;
                
                while (current < right) {
                    if (nums[left] + nums[current] + nums[right] == 0) {
                        vector<int> temp;
                        temp.push_back(nums[left]);
                        temp.push_back(nums[current]);
                        temp.push_back(nums[right]);
                        resultArray.push_back(temp);
                        while(current < right && nums[current] == nums[current + 1]) {
                            current++;
                        }
                        while(current < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        current++; right--;
                    } else if (nums[left] + nums[current] + nums[right] < 0) {
                        current++;
                    } else {
                        right--;
                    }
                }
            }
            return resultArray;

            // Time Complexity - O(n^2) Space Complexity - O(1)
        }
    };