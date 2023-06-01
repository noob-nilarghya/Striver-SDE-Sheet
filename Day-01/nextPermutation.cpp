#include <bits/stdc++.h> 
// Purely striver's solution. 

vector<int> nextPermutation(vector<int> &permute, int n){
    int idx=-1;
    for(int i=permute.size()-1; i>0; i--){
        if(permute[i-1]<permute[i]){ // find i such that permute[i-1]<prmute[i]. Store "idx= i-1"
            idx=i-1; break;
        }
    }
    if(idx==-1){ // [5,4,3,2,1] ----> [1,2,3,4,5]
        reverse(permute.begin(), permute.end());
        return permute;
    }
    int idx2=-1;
    for(int j=permute.size()-1; j>=0; j--){ // find j such that permute[j]>permute[idx]
        if(permute[j]>permute[idx]){
            idx2=j; break;
        }
    }
    swap(permute[idx], permute[idx2]); // swap idx and j
    reverse(permute.begin()+idx+1, permute.end()); // reverse from idx+1 till end

    return permute;
}

// Time Complexity: O(n+n+n) ~ O(n)
// Space Complexity: O(1)