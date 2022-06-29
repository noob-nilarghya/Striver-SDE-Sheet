#include <bits/stdc++.h>

long helper(int* deno, int idx, int n, int value, vector<vector<long>>& dp){
    if(value<0){ return 0; }
    if(value==0){
        return 1;
    }
    if(idx>=n && value !=0){
        return 0;
    }
    if(dp[idx][value] != -1){ return dp[idx][value]; }
    long a= helper(deno, idx, n, value-deno[idx], dp); // unbounded inclusion
    long b= helper(deno, idx+1, n, value, dp); // exclusion
    return ( dp[idx][value]=(a+b) );
}

long countWaysToMakeChange(int* denominations, int n, int value){
    vector<vector<long>> dp(n+1, vector<long>(value+1, -1));
    return helper(denominations, 0, n, value, dp);
}