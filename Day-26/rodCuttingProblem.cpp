// Nearly same as UNBOUNDED KNAPSACK
// RECURSION

int helper(vector<int>& length, vector<int>& price, int n, int maxLen){
    if(maxLen==0){
        return 0;
    }
    if(n==0){
        if(maxLen%length[0] == 0){
            return (maxLen/length[0])*price[0];
        }
        else { return 0; }
    }
    
    int take=-1e9;
    if(maxLen>=length[n]){
        take=helper(length, price, n, maxLen-length[n]) + price[n];
    }
    int notTake= helper(length, price, n-1, maxLen);
    return max(take, notTake);
}

int cutRod(vector<int> &price, int n){
	vector<int> length(n);
    for(int i=0; i<n; i++){
        length[i]=i+1;
    }
    return helper(length, price, n-1, n);
}

//TABULATION

int cutRod(vector<int> &price, int n){
	vector<int> length(n);
    for(int i=0; i<n; i++){
        length[i]=i+1;
    }
    
    int maxLen=n;
    vector<vector<int>> dp(n, vector<int>(maxLen+1));
    for(int i=0; i<n; i++){
        dp[i][0]=0;
    }
    for(int j=0; j<=maxLen; j++){
        if(j%length[0]==0){
            dp[0][j]= (j/length[0])*price[0];
        }
        else{
            if(j!=0) dp[0][j]=0;
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=maxLen; j++){
            int take=-1e9;
            if(j>=length[i]){
                take= dp[i][j-length[i]]+ price[i];
            }
            int notTake= dp[i-1][j];
            dp[i][j]=max(take, notTake);
        }
    }
    return dp[n-1][maxLen];
}
