// MEMOIZATION
int helper(vector<int>& value, vector<int>& weight, int idx, int n, int wt, vector<vector<int>>& dp){
    if(idx>=n || wt<=0){
        return 0;
    }
    if(idx<n && wt<=0){
        return 0;
    }
    if(dp[idx][wt] != -1){ return dp[idx][wt]; }
    if(wt<weight[idx]){ // exclusion call only
        return (dp[idx][wt]= helper(value, weight, idx+1, n, wt, dp) );
    }
    int a= helper(value, weight, idx+1, n, wt, dp);
    int b= helper(value, weight, idx+1, n, wt-weight[idx], dp)+value[idx];
    return ( dp[idx][wt] = max(a,b) );
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
    return helper(values, weights, 0, n, w, dp);
}
//-------------------------------------------------------------------------------------------------

// DP
int maxProfit(vector<int> &value, vector<int> &weight, int n, int w){
    vector<vector<int>> dp(n+1, vector<int>(w+1));
    for(int i=0; i<=n; i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=w; j++){
        dp[n][j]=0;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=w; j++){
            if(weight[i]>j){
                dp[i][j]=dp[i+1][j];
            }
            else{
                int a=dp[i+1][j];
                int b=dp[i+1][j-weight[i]]+value[i];
                dp[i][j]=max(a,b);
            }
        }
    }
    return dp[0][w];
}