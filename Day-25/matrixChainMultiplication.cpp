int helper(vector<int>& arr, vector<vector<int>>& dp, int start, int end){
    if(start+1>=end){
        return 0;
    }
    else if(start+2==end){
        return arr[start]*arr[start+1]*arr[end];
    }
    if(dp[start][end] != -1){ return dp[start][end]; }
    int mn=INT_MAX;
    for(int i=start+1; i<=end-1; i++){
        int a= helper(arr, dp, start, i);
        int b= helper(arr, dp, i, end);
        int res= a+b+(arr[start]*arr[i]*arr[end]);
        mn=min(mn,res);
    }
    dp[start][end]=mn;
    return mn;
}

int matrixMultiplication(vector<int> &arr, int N){
    vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
    return helper(arr, dp, 0, N-1);
}