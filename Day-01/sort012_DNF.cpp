#include <bits/stdc++.h> 
// Dutch National Flag Algorithm (DNF): Intution:
/*    All 0's should be between [0, low-2]
      All 2's should be between [high+1, size-1]
      All 1's should be inbetween
*/

void sort012(int *arr, int n){
    // make 3 pointer: low=0, mid=0, high=size-1
    int low=0; int mid=0; int high= n-1;
    while(mid<=high){ //mid should not cross high
        // Traverse mid:
        if(arr[mid]==0){ // swap(mid, low) and mid++, low++
           swap(arr[low], arr[mid]);
            mid++; low++;
        }
        else if(arr[mid]==1){ // do nothing, just mid++
            mid++;
        }
        else if(arr[mid]==2){ // swap(mid, high) and high--
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Time Complexity: O(n)
// Space Complexity: O(1)