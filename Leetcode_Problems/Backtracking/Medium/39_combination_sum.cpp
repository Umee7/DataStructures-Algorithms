#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void findCombinations(int index, int target, vector<int> &temp, vector<vector<int>> &result, vector<int> &candidates) {
        // Base Case 
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        // Negative Case
        if(target < 0 || index == candidates.size()) {
            return;
        }

        //Pick Case
        temp.push_back(candidates[index]);
        findCombinations(index, target - candidates[index], temp ,result, candidates);
        //Backtrack
        temp.pop_back();
        // Not Pick case
        findCombinations(index + 1, target, temp, result, candidates);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        findCombinations(0, target, temp, result, candidates);
        return result;
    }
};