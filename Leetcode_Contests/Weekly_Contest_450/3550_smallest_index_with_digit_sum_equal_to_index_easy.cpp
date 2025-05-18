#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int smallestIndex(vector<int>& nums) {

            // My Solution
            int digitSum = 0;
            for(int i = 0; i < nums.size(); i++) {
                int number = nums[i];
                string str = to_string(number);
                
                for(char ch : str) {
                    int digit = ch - '0';
                    digitSum += digit;
                }
                
                if(digitSum == i) return i;
                digitSum = 0;
            }
            return -1;

            // Status - Accepted
        }
};