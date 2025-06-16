#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // My  Bruteforce
        // unordered_map<int, int> elements;
        // vector<int> resultArray;
        // for(int element : nums) elements[element]++;

        // for(auto element : elements) {
        //     if(element.second > round(nums.size() / 3)) resultArray.push_back(element.first);
        // }
        // return resultArray;

        // Time Complexity: O(n) Space Complexity: O(n)

        // Optimal solution - Boyer-Moore Voting Algorithm
        int candidate1;
        int candidate2;
        int votes1 = 0;
        int votes2 = 0;
        for(int num : nums) {
            if(votes1 > 0 && candidate1 == num) {
                votes1++;
            } else if(votes2 > 0 && candidate2 == num) {
                votes2++;
            } else if(votes1 == 0) {
                candidate1 = num;
                votes1 = 1;
            } else if(votes2 == 0) {
                candidate2 = num;
                votes2 = 1;
            } else {
                votes1--;
                votes2--;
            }
        }

        votes1 = votes2 = 0;
        
        for(int num : nums) {
            if(candidate1 == num) {
                votes1++;
            } else if(candidate2 == num) {
                votes2++;
            }
        }

        vector<int> majorityElements;
        if(votes1 > round(nums.size()/3)){
            majorityElements.push_back(candidate1);
        }
        
        if(votes2 > round(nums.size() / 3)) {
            majorityElements.push_back(candidate2);
        };
        return majorityElements;

        // Time Complexity - O(n) Space Complexity - O(1)
    }
};