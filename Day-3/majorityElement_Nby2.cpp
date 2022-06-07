#include <bits/stdc++.h> 
// Moore Vooting Algorithm
// Here majority element means freq>n/2. So there would be at max, 1 elemnt possible to become majority element.
/* Intution: Two different element will cancel each other, 
If majority element exist, it can't be cancelled completely. Also we will verify answer */

int findMajorityElement(int arr[], int n) {
	int major=arr[0]; int cnt=1; // assuming arr[0] as major element
    for(int i=1; i<n; i++){
        if(arr[i]==major){
            cnt++;
        }
        else if(arr[i] != major){
            cnt--;
            if(cnt==0){
                major=arr[i]; cnt=1; // update major & count
            }
        }
    }
    // Now major is our one of the potential Candidate, we need to verify now !

    int majorCnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]==major){ majorCnt++; }
    }
    if(majorCnt > n/2){ return major; }
    return -1;
}

// Time Complexity: O(n)
// Space Complexity: O(1)