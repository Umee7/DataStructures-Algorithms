#include<bits/stdc++.h>
using namespace std;

// 1. Recursion
class Solution {
public:
    int findUniquePaths(int m, int n, vector<vector<int>> &obstacleGrid) {
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) return 0; 
        if(m == 0 && n == 0) return 1;

        int right = findUniquePaths(m - 1, n, obstacleGrid);
        int bottom = findUniquePaths(m, n - 1, obstacleGrid);
        return dp[m][n] = right + bottom; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1, n = obstacleGrid[0].size() - 1;
        if(obstacleGrid[m][n] == 1 || obstacleGrid[m][n] == 1) return 0;
        return findUniquePaths(m, n , obstacleGrid);
    }
};


// 2. Memoisation
class Solution {
public:
    int findUniquePaths(int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp) {
        if(m < 0 || n < 0) return 0;
        if(obstacleGrid[m][n] == 1) return 0; 
        if(m == 0 && n == 0) return 1;

        if(dp[m][n] != -1) return dp[m][n];
        int right = findUniquePaths(m - 1, n, obstacleGrid, dp);
        int bottom = findUniquePaths(m, n - 1, obstacleGrid, dp);
        return dp[m][n] = right + bottom; 
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1, n = obstacleGrid[0].size() - 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        if(obstacleGrid[m][n] == 1 || obstacleGrid[m][n] == 1) return 0;
        return findUniquePaths(m, n , obstacleGrid, dp);
    }
};

// Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1, n = obstacleGrid[0].size() - 1;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m][n] == 1) return 0;

        // Fill First Row
        for(int i = 0; i <= n; i++) {
            if(obstacleGrid[0][i] == 1) {
                dp[0][i] = 0; break;
            } else {
                dp[0][i] = 1;
            }
        }

        // Fill First Col
        for(int i = 0; i <= m; i++) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0; break;
            } else {
                dp[i][0] = 1;
            }
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m][n];
    }
};