#include <bits/stdc++.h>

// When you just need to return the size 
int removeDuplicates(vector<int> &arr, int n) {
	int cnt=0; int num=INT_MAX; // some random value 
    for(int i=0; i<n; i++){
        if(num != arr[i]){
            cnt++; num=arr[i];
        }
        else if( num == arr[i] ){  continue;  }
    }
    return cnt;
}

//-----------------------------------------------------------------------

// When you need to print the actual unique element array [IMP]
int removeDuplicates(vector<int> &arr, int n) {
    // As the arry is sorted, so we can think of 2 pointer approach
    // INTUTION: (i) will always points to the first appeared index of a number. (j) will iterate through arr.
    // When (j)!=(i), it denotes, (j) had found a new ele (j is at the first appered indx of that number)
    // So move i++ (as (i) was pointing to the first appeared index of a number), and copy arr[j] in arr[i]
    // So, now again (i) is pointing to first appeared indx of newNum
    int i=0;
    for(int j=1; j<n; j++){
        if(arr[i]==arr[j]){ continue; }
        else if( arr[i] != arr[j] ){
            i++;
            arr[i]=arr[j];
        }
    }
    /*
    // If we need to print then
    for(int idx=0; idx<=i; idx++){
        cout<<arr[idx]<<" ";
    }*/

    return (i+1);
}

// Time Complexity: O(N)
// Space Complexity: O(1)