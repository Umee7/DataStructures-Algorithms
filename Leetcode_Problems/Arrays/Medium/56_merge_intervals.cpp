#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Bruteforce 
        // Bruteforce
        // sort(intervals.begin(), intervals.end());
        // vector<vector<int>> resultArray;
        // for(int i = 0; i < intervals.size(); i++) {
        //     int start = intervals[i][0];
        //     int end = intervals[i][1];
        //     if(!resultArray.empty() && start <= resultArray.back()[1]) {
        //         continue;
        //     }
        //     for(int j = i + 1; j < intervals.size(); j++) {
        //         if(end >= intervals[j][0]) {
        //             end = max(end, intervals[j][1]);
        //         } else {
        //             break;
        //         }
        //     }
        //     resultArray.push_back({start, end});
        // }
        // my optimal
        // sort(intervals.begin(), intervals.end());
        // int left = 0, right = 1;
        // vector<vector<int>> resultArray;
        // int start = intervals[left][0], end = intervals[left][1];
        // while(left < right && right < intervals.size()) {
        //     if((end >= intervals[right][0])) {
        //         end = max(end, intervals[right][1]);
        //     } else {
        //         resultArray.push_back({start, end});
        //         start = intervals[right][0];
        //         end = intervals[right][1];
        //     }
        //     left++; right++;
        // }
        // resultArray.push_back({start, end});
        // return resultArray;
        // Time Complexity - O(n) Space Complexity - O(1)

        // I could write it much cleaner without two pointer. - referred from striver
        sort(intervals.begin(), intervals.end());
        int left = 0, right = 1;
        vector<vector<int>> resultArray;
        int start = intervals[left][0], end = intervals[left][1];
        for(int i = 0; i < intervals.size(); i++) {
            if(resultArray.empty() || resultArray.back()[1] < intervals[i][0]) {
                resultArray.push_back({intervals[i]});
            } else {
                resultArray.back()[1] = intervals[i][1];
            }
        }

        return resultArray;
    }
};