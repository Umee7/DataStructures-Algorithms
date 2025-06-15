#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // My  Bruteforce
        unordered_map<int, int> elements;
        vector<int> resultArray;
        for(int element : nums) elements[element]++;

        for(auto element : elements) {
            if(element.second > round(nums.size() / 3)) resultArray.push_back(element.first);
        }
        return resultArray;

        // Time Complexity: O(n) Space Complexity: O(n)
    }
};