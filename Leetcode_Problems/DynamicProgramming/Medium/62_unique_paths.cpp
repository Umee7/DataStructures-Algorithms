#include<bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
public:
    int findPaths(int m, int n) {
        if(m == 1 && n == 1) {
            return 1;
        }

        if(m < 1 || n < 1) return 0; 

        return findPaths(m - 1, n, dp) + findPaths(m, n - 1, dp);
    }
    
    int uniquePaths(int m, int n) {
        return findPaths(m, n, dp);
    }
};

// Memoisation
class Solution {
public:
    int findPaths(int m, int n, vector<vector<int>> &dp) {
        if(m == 1 && n == 1) {
            return 1;
        }

        if(m < 1 || n < 1) return 0; 

        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = findPaths(m - 1, n, dp) + findPaths(m, n - 1, dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return findPaths(m, n, dp);
    }
};

// Tabulation 
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        
        // Initialize last row with 1
        for(int i = 0; i < m - 1; i++) {
            dp[i][n-1]  = 1;
        }

        // Initialize last col with 1
        for(int j = 0; j < n - 1; j++) {
            dp[m-1][j]  = 1;
        }

        for(int i = m - 2; i >= 0; i--) {
            for(int j = n - 2; j >= 0; j--) {
                dp[i][j] = dp[i+1][j] +  dp[i][j+1];
            }
        }

        return dp[0][0] ? dp[0][0] : 1;
    }
};