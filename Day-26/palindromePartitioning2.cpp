#include <bits/stdc++.h> 

vector<vector<int>> longestPalinSubstring(string& str){
    int n= str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){ dp[i][i]=1; } // substr of len 1
    for(int i=0; i<n-1; i++){ // substr of len 1
        if(str[i]==str[i+1]){
            dp[i][i+1]=1;
        }
    }

    for(int len=3; len<=str.size(); len++){
        for(int i=0; i<=str.size()-len; i++){
            int first=i; int last= i+len-1;
            if(str[first]==str[last] && dp[first+1][last-1]==1){
                dp[first][last]=1;
            }
        }
    }
    return dp;
}

int helper(int idx, string& str, vector<vector<int>>& dp, vector<int>& dp2){
    if(idx>=str.size()){ return 0; }
    if(dp2[idx]!=-1){ return dp2[idx]; }

    int minAns= INT_MAX;
    for(int i=idx; i<str.size(); i++){
        if(dp[idx][i]==1){ // substring [idx, i] is a palindrome
            minAns = min(minAns, helper(i + 1, str, dp, dp2));
        }
    }
    return dp2[idx]=minAns +1;
}

int palindromePartitioning(string str) {
    int n= str.size();
    vector<vector<int>> dp= longestPalinSubstring(str);
    vector<int> dp2(str.size()+1, -1);
    return helper(0, str, dp, dp2) -1; 
}
