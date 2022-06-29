#include <bits/stdc++.h>

int lcs(string s, string t){
	int m=s.length(); int n=t.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for(int i=0; i<=m; i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=n; j++){
        dp[0][j]=0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s[m-i]==t[n-j]){ // 1st char is same
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                int a=dp[i-1][j-1];
                int b=dp[i][j-1];
                int c=dp[i-1][j];
                dp[i][j]= max(a, max(b, c));
            }
        }
    }
    return dp[m][n];
}