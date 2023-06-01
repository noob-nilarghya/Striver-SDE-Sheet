#include <bits/stdc++.h>

string longestPalinSubstring(string str){
    int n= str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0)); // 0 means false, 1 means true

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

    int maxiLen=INT_MIN; int first; int last;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(dp[i][j]==1 && maxiLen<(j-i+1)){
                maxiLen= j-i+1;
                first=i; last=j;
            }
        }
    }
    string ans="";
    for(int i=first; i<=last; i++){ ans+=str[i]; }
    return ans;
}