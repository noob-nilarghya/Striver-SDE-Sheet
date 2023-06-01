#include <bits/stdc++.h> 

long getTrappedWater(long *arr, int n){
    long* leftMax= new long[n]; long left=INT_MIN;
    long* rightMax=new long[n]; long right=INT_MIN;
    
    for(int i=0; i<n; i++){
        left=max(left, arr[i]);
        leftMax[i]=left; 
    }
    for(int i=n-1; i>=0; i--){
        right=max(right, arr[i]);
        rightMax[i]=right;
    }
    long sum=0;
    for(int i=0; i<n; i++){
        sum+=( min(leftMax[i], rightMax[i]) - arr[i] );
    }
    return sum;
}

// Time Complexity: O(N)
// Space Complexity: O(N)