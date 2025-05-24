#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // My Solution
        if(nums.empty()) return 0;
        vector<int> sortedArray(nums);
        sort(sortedArray.begin(), sortedArray.end());
        int maxLength = 1;
        int currentLength = 1;
        for(int i = 1; i < sortedArray.size(); i++) {
            if(sortedArray[i]==sortedArray[i-1]+1){
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else if(sortedArray[i]==sortedArray[i-1]){
                continue;
            } else {
                currentLength = 1;
            }   
        }
        return maxLength;

        // Time Complexity 0(n) Space Complexity 0(n)
    }
};