#include <bits/stdc++.h> 

int helper(int row, int col, vector<vector<int>>& dp, int m, int n){
    if(row==m-1 && col==n-1){
        dp[row][col]=1;
        return 1;
    }
    if(row<0 || row>=m || col<0 || col>=n){ return 0; }
    
    if(dp[row][col]!=-1){ return dp[row][col]; }
    
    int a= helper(row+1, col, dp, m, n);
    int b= helper(row, col+1, dp, m, n);
    
    dp[row][col]=a+b;
    return a+b;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
	return helper(0, 0, dp, m, n);
}

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)