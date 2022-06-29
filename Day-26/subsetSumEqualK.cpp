bool helper(vector<int>& arr, int idx, int n, int k, int** dp){
    if(k<0){ return false; }
    if(idx>=n && k!=0){
        return false;
    }
    if(k==0){
        return true;
    }

    if(dp[idx][k] != -1){
        if(dp[idx][k]==1){ return true; }
        else if(dp[idx][k]==0){ return false; }
    }
    bool a= helper(arr, idx+1, n, k-arr[idx], dp);
    if(a==true){ 
        dp[idx][k]=1;
        return true; 
    }
    bool b= helper(arr, idx+1, n, k, dp);
    if(b==true){ 
        dp[idx][k]=1;
        return true; 
    }
    dp[idx][k]=0;
    return false;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    int** dp= new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i]= new int[k+1];
        for(int j=0; j<=k; j++){
            dp[i][j]=-1;
        }
    }
    return helper(arr, 0, n, k, dp);
}