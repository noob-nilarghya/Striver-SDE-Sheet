// MEMOIZATION

int helper(string str1, string str2, vector<vector<int>>& dp){
    if(str1.size()==0 || str2.size()==0){
        return max(str1.size(), str2.size());
    }
    int m=str1.size(); int n=str2.size();
    if(dp[m][n] != -1){ return dp[m][n]; }
    if(str1[0]==str2[0]){
        dp[m][n]= helper(str1.substr(1), str2.substr(1), dp);
        return dp[m][n];
    }
    int a= helper(str1.substr(1), str2, dp);
    int b= helper(str1, str2.substr(1), dp);
    int c= helper(str1.substr(1), str2.substr(1), dp);
    dp[m][n]=min(a, min(b,c))+1;
    return min(a, min(b,c))+1;
}

int editDistance(string str1, string str2){
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
    return helper(str1, str2, dp);
}

//---------------------------------------------------------------------------------

// DP

int editDistance(string str1, string str2){
    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1));
    int m=str1.size(); int n=str2.size();
    for(int i=0; i<=m; i++){ // str2.size() == 0
        dp[i][0]=i;
    }
    for(int j=0; j<=n; j++){ // str1.size() == 0
        dp[0][j]=j;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[m-i]==str2[n-j]){ // 1st char is same
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int a= dp[i][j-1];
                int b= dp[i-1][j];
                int c= dp[i-1][j-1];
                dp[i][j]= min(a, min(b, c))+1;
            }
        }
    }
    return dp[m][n];
}