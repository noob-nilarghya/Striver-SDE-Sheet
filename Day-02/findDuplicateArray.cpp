#include <bits/stdc++.h> 

int findDuplicate(vector<int> &arr, int n){
	sort(arr.begin(), arr.end());
    for(int i=1; i<arr.size(); i++){
        if(arr[i]==arr[i-1]){
            return arr[i];
        }
    }
    return -1;
}

//Time Complexity: O(n)
// Space Complexity: O(1)