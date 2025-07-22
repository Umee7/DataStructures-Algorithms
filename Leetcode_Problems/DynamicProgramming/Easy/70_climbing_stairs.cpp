#include<bits/stdc++.h>
using namespace std;

// 1. Recursive Solution
class Solution {
    int climbStaris(int n) {
        return findWays(n);
    }
    
    int findWays(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        return findWays(n-1) + findWays(n-2);
    }
}

// Dynamic Programming

// 2. Memoization

class Solution {
    int climbStaris(int n) {
        vector<int> dp(n+1, -1);
        return findWays(n);
    }
    
    int findWays(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];
        return dp[n] = findWays(n-1) + findWays(n-2);
    }
}

// 3. Tabulation

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        return findWays(n, dp);
    }

    int findWays(int n, vector<int> &dp) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};