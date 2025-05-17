#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            // My Bruteforce || Optimal
            unordered_map<int, int> colors;
            for (int num : nums)
                colors[num]++;
    
            int index = 0;
            int color = 0;
            int colorCount = 0;
            while (color < 3) {
                while (index < nums.size() && colorCount < colors[color]) {
                    nums[index] = color;
                    index++;
                    colorCount++;
                }
                colorCount = 0;
                color++;
            }
            // Time Complexity - O(n) Space Complexity - O(1)
        }
    };
    