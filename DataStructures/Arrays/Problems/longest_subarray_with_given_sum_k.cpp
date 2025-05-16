#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        // Solution
        int maxLength = 0;
        int currentSum = 0;
        int left = 0;
        int right = 0;

        // My optimal approach
        // while(right < nums.size()) {
        //     if(currentSum + nums[right] < k) {
        //         currentSum += nums[right];
        //         right++;
        //     } else if (currentSum + nums[right] > k) {
        //         currentSum -= nums[left];
        //         left++;
        //     } else {
        //         currentSum += nums[right];
        //         maxLength = max(maxLength, right - left + 1);
        //         right++;
        //     }
        // };

        // Improvised removing redundant conditions
        while(right < nums.size()) {
            currentSum += nums[right];

            while(currentSum > k && left <= right) {
                currentSum -= nums[left];
                left++;
            }

            if(currentSum == k) {
                maxLength = max(maxLength, right - left + 1);
            }

            right++;
        }

        // Approach : Sliding Window
        // Time Complexity :  O(n) Space Complexity : O(1)
        // Note : Window shrinking logic in my code can be improvised with while loop

        return maxLength;
    }
};


int main() {
    vector<int> nums = {5, 1, 1, 1, 1, 1, 1};
    int k = 3;
    
    Solution solution;
    int maxSubarray = solution.longestSubarray(nums, k);
    cout<<maxSubarray<<endl;

}
