#include <bits/stdc++.h> 
// Kadane Algorithm

long long maxSubarraySum(int arr[], int n){
    // modification: If all elemnt are -ve, return 0 (instead of lowest -ve)
    int flag=0;
    for(int i=0; i<n; i++){  if(arr[i]>=0){flag=1; break;}  }
    if(flag==0){ return 0; }
    
    // rest of the code is as usual
    long long int sum=0; long long int maxSum=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxSum=max(maxSum, sum);
        if(sum<0){ 
            sum=0;
        }
    }

    return maxSum;
}

// Time Complexity: O(n+n) ~ O(n)
// Space Complexity: O(1)