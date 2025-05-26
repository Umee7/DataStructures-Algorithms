#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle; 
        int index = 1;
        while(index <= numRows){
            vector<int> row(index, 1);
            if(index > 2) {
                for(int i = 1; i < row.size() - 1; i++) {
                    row[i] = pascalsTriangle[index-2][i-1] + pascalsTriangle[index-2][i];
                }
            }
            pascalsTriangle.push_back(row);
            index++;
        }
        return pascalsTriangle;
    }
};