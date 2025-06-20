#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // My Bruteforce
        // int index = 0;
        // int index2 = 0;
        // while(index2 < nums2.size()) {
        //     while(nums1[index]!=0){
        //         index++;
        //     }
        //     nums1[index++] = nums2[index2++];
        // }    
        // sort(nums1.begin(), nums1.end());

        // My Optimal Solution 

        int right = nums2.size() - 1, left = m - 1;
        for(int i = nums1.size() - 1; i >= 0; i--) {
            if(right < 0) {
                break;
            }
            if(left >= 0 && nums1[left] >= nums2[right]) {
                nums1[i] = nums1[left];
                left--;
            } else {
                nums1[i] = nums2[right];
                right--;
            } 
        }

        // Time Complexity - O(m + n) Space Complexity O(1)
    }
};