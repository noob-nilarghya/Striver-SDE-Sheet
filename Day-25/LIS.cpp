#include <bits/stdc++.h>

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> lis(n);
    lis[0]=1;
    for(int i=1; i<n; i++){
        int mx=INT_MIN;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                mx=max(mx, lis[j]);
            }
        }
        if(mx==INT_MIN){ // all ele from [0,i-1] are smaller than arr[i]
            lis[i]=1;
        }
        else{
            lis[i]=mx+1;
        } 
    }
    return *max_element(lis.begin(), lis.end());
}
