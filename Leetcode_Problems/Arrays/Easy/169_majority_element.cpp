#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {

            // My Bruteforce
            unordered_map<int, int> elements;
            for(int num : nums) elements[num]++;
            
            int majorityElement = -1;
            for(auto element : elements) {
                if(element.second > nums.size() / 2) {
                    majorityElement = element.first;
                    return majorityElement;
                }
            }
            return majorityElement;
            // Time Complexity - O(n) Space Complexity - O(n)
            // Optimal one exists with Booyer-Moore voting algorithm with Space Complexity - O(1)
        }
    };