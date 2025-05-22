#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {

            // My Bruteforce
            // unordered_map<int, int> elements;
            // for(int num : nums) elements[num]++;
            
            // int majorityElement = -1;
            // for(auto element : elements) {
            //     if(element.second > nums.size() / 2) {
            //         majorityElement = element.first;
            //         return majorityElement;
            //     }
            // }
            // return majorityElement;
            // Time Complexity - O(n) Space Complexity - O(n)

            // Optimal 
            // Boyer-Moore Algorithm
            int votes = 0;
            int candidate = 0;
            for(int i = 0; i < nums.size(); i++) {
                if(votes == 0) {
                    candidate = nums[i];
                }
                votes += ((candidate == nums[i]) ? 1 : -1);
            }
            return candidate;

        }
    };