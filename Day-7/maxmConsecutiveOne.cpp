#include <bits/stdc++.h>
// variable sized slidding window 

int longestSubSeg(vector<int> &arr , int n, int k){
    int i=0; int j=0; int cntZero=0; int maxLen=INT_MIN;
    while(j<n){
        if(arr[j]==0){ cntZero++; } //calculation for j
        
        if(cntZero<=k){
            maxLen=max(maxLen, (j-i+1));
            j++;
        }
        else if(cntZero>k){ // now we have to DECREASE WINDOW SIZE
            while(i<j && cntZero>k){
                if(arr[i]==0){ cntZero--; }
                i++;
            }
            if(cntZero<=k){
                maxLen=max(maxLen, (j-i+1));
            }
            j++;
        }
    }
    if(maxLen==INT_MIN){ return 0; }
    return maxLen;
}

// Time Complexity: O(N)
// Space Comlplexity: O(1)
