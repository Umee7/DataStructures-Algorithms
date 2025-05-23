#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            // My bruteforce
            unordered_multimap<int, int> zeroes;
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    if (matrix[i][j] == 0)
                        zeroes.insert({i, j});
                }
            }
    
            for (auto zero : zeroes) {
                for (int i = 0; i < matrix[zero.first].size(); i++) {
                    matrix[zero.first][i] = 0;
                }
    
                for(int i = 0; i < matrix.size(); i++){
                    matrix[i][zero.second] = 0;
                }
            }
            // Time Complexity O(m x n + k x (n + m)) Space Complexity O(k) where k is the number of zeroes
        }
    };