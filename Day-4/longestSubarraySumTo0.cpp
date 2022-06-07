// If you think of variable sized sliding window, then you will stuck at a point. Think WHY?

#include <bits/stdc++.h> 

int LongestSubsetWithZeroSum(vector<int>& arr) {
    int sum=0; int n=arr.size();
    unordered_map<int, int> m; m[sum]=0; int len=INT_MIN;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(m.count(sum)>0){
            len=max(len, i-m[sum]+1);
        }
        else if(m.count(sum)==0){
            m[sum]=i+1;
        }
    }
    if(len==INT_MIN){ return 0; }
    return len;
}

// Time Complexity: O(N)
// Space Complexity: O(N)