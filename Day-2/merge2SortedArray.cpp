#include <bits/stdc++.h> 

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n){
    
    // METHOD 1: USUAL GHISA PITA METHOD
    vector<int> ans(m+n, 0);
    int i=0; int j=0; int k=0;
    while(i<m && j<n){
        if(arr1[i]< arr2[j]){
            ans[k]=arr1[i];
            k++; i++;
        }
        else{
            ans[k]=arr2[j];
            k++; j++;
        }
    }
    while(i<m){
        ans[k]=arr1[i];
        k++; i++;
    }
    while(j<n){
        ans[k]=arr2[j];
        k++; j++;
    }
    arr1=ans;
    return ans;
    //---------------------------------------------------
    // METHOD 2: SIMPLY SORT IT
    
    int i=m;
    for(int idx=0; idx<n; idx++){
        arr1[i]=arr2[idx];
        i++;
    }
    sort(arr1.begin(), arr1.end());
    return arr1;
    
    
    // Gap method: Useless but can be revised from Striver video
}

// Time Complexity: Method1-> O(m+n), Method2-> O(n+(m+n)log(m+n))
// Space Complexity: Method1-> O(m+n), Method2-> O(1)