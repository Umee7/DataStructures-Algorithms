#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        // Solution
        vector<int> solution;
        int left = 0;
        int right = 0;
        while(left < nums1.size() && right < nums2.size()) {
            if(nums1[left] < nums2[right]) {
                if(solution.empty() || solution.back() != nums1[left]){
                    solution.push_back(nums1[left]);
                }
                left++;
            } else if(nums1[left] == nums2[right]) {
                if(solution.empty() || solution.back() != nums1[left]){
                    solution.push_back(nums1[left]);
                }
                left++;
                right++;
            } else {
                if(solution.size() && nums2[right] > solution[solution.size()-1]) {
                    solution.push_back(nums2[right]);
                }
                right++;
            }
        }
        
        while(left<nums1.size()) {
            if(solution.empty() || solution.back() != nums1[left]){
                    solution.push_back(nums1[left]);
                }
            left++;
        }
        
        while(right<nums2.size()) {
            if(solution.empty() || solution.back() != nums2[right]){
                    solution.push_back(nums2[right]);
                }
                right++;
        }
    
        
        return solution;
    }
};

int main() {
    vector<int> nums1 = {3, 4, 6, 7, 9, 9};
    vector<int> nums2 = {1, 5, 7, 8, 8};
    Solution answer =  Solution();
    vector<int> solution = answer.unionArray(nums1, nums2);
    for(int i = 0; i < solution.size(); i++) {
        cout<<solution[i]<<" ";
    }
};