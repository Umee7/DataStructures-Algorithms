#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
    void print1ToN(int n) {
        if(n < 1) return;
        print1ToN(n-1);
        cout<<n<<" ";
    }
    
    int sumOfN(int n) {
        if(n == 1) return 1;
        return n + sumOfN(n-1);
    }
    
    int factOfN(int n) {
        if(n == 1) return 1;
        return n * factOfN(n-1);
    }
    
    void reverseArray(vector<int> &nums, int low, int high) {
        if(low >= high)return;
        swap(nums[low], nums[high]);
        reverseArray(nums, low+1, high-1);
    }
    
    bool isPalindrome(int i, string s) {
        if(i >= s.size() / 2) return true;
        if(s[i] != s[s.size()-i-1]) return false;
        
        return isPalindrome(i+1, s);
        
    }
    
    int fibNum(int n) {
        if(n < 2) return n;
        
        return fibNum(n-1) + fibNum(n-2);
    }
    void findS(int index, vector<int> &temp, vector<int> &nums, set<vector<int>> &result) {
        if(index == nums.size()) {
            if(temp.size() != 0) {
                result.insert(temp);
            }
            return;
        }
        
        // Pick
        temp.push_back(nums[index]);
        findS(index + 1, temp, nums, result);
        temp.pop_back();
        
        // Not Pick
        findS(index+1, temp, nums, result);
        
        
    }
    
    set<vector<int>> findSubsequences(vector<int> &nums) {
        set<vector<int>> result;
        vector<int> temp;
        findS(0, temp, nums, result);
        return result;
        
    }
    
};


int main() {
	int n = 9;
	Solution solution;
    // solution.print1ToN(n);
    int sumOfN = solution.sumOfN(n);
    int factOfN = solution.factOfN(n);
    // cout<<factOfN<<" ";
    vector<int> nums = {6, 5, 4, 3, 2, 1};
    solution.reverseArray(nums, 0, 5);
    // for(int num : nums) cout<<num<<" ";
    string s = "statp";
    // cout << solution.isPalindrome(0, s);
    // cout << solution.fibNum(n);
    vector<int> subsequence = {1, 2, 3};
    set<vector<int>> ss = solution.findSubsequences(subsequence);
    for(auto sub : ss){
        cout<<"[ ";
        for(auto array : sub) {
            cout<<array<<" ";
        }
        cout<<"]";
    }
}
