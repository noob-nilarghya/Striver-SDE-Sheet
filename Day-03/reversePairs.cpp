
// I tried this code by myself (inspired from "count inversions" problem).
// All test cases got passed, but optimal test was not passed 

#include <bits/stdc++.h> 
int cnt=0;

// DRY RUN ON: [1,2,3,2,3,1] ---> o/p: 2
void merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end){
    int i=start; int j=mid+1; int k=start;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++; i++;
        }
        else if(arr[i]>=arr[j]){ 
            for(int idx=i; idx<=mid; idx++){ // DRY RUN
                if(arr[idx]>2*arr[j]){
                    cnt+=(mid-idx+1);
                    break;
                }
            }
            temp[k]=arr[j];
            k++; j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++; i++;
    }
    while(j<=end){
        temp[k]=arr[j];
        k++; j++;
    }
    for(int idx=start; idx<=end; idx++){
        arr[idx]=temp[idx];
    }
    return;
}

void mergeSort(vector<int>& arr, vector<int>& temp, int start, int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, mid+1, end);
    merge(arr, temp, start, mid, end);
    return;
}

int reversePairs(vector<int> &arr, int n){
    cnt=0;
    vector<int> temp(n, 0);
	mergeSort(arr, temp, 0, n-1);
    return cnt;
}

// Time Complexity: O(N^2logN)+O(N) [ O(n) is for copy from temp to arr]
// Space Complexity: O(N)

// ---------------------------------------------------------------------------------
// Final Solution :

#include <bits/stdc++.h> 
int cnt=0;

// DRY RUN ON: [40,25,19,12,9,6,2] ---> o/p: 15
void merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end){
    int Lidx=start; int Ridx=mid+1;
    for(Lidx=start; Lidx<=mid; Lidx++){
        while(Ridx<=end && arr[Lidx] > 2LL*arr[Ridx]){ // Run the loop till arr[Lidx] <= 2*arr[Ridx]
            Ridx++;
        }
        // Now arr[Lidx] <= 2*arr[Ridx], 
        // so, derired pairs are: {arr[Lidx], each num of rightHalf from [mid+1, Ridx-1]}
        cnt+=((Ridx-1)-(mid+1)+1);
    }
    int i=start; int j=mid+1; int k=start;
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp[k]=arr[i];
            k++; i++;
        }
        else if(arr[i]>=arr[j]){  
            temp[k]=arr[j];
            k++; j++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++; i++;
    }
    while(j<=end){
        temp[k]=arr[j];
        k++; j++;
    }
    for(int idx=start; idx<=end; idx++){
        arr[idx]=temp[idx];
    }
    return;
}

void mergeSort(vector<int>& arr, vector<int>& temp, int start, int end){
    if(start>=end){
        return;
    }
    int mid=start+(end-start)/2;
    mergeSort(arr, temp, start, mid);
    mergeSort(arr, temp, mid+1, end);
    merge(arr, temp, start, mid, end);
    return;
}

int reversePairs(vector<int> &arr, int n){
    cnt=0;
    vector<int> temp(n, 0);
	mergeSort(arr, temp, 0, n-1);
    return cnt;
}

// Time Complexity: O(NlogN)+O(N)+O(N) [ O(N) is for copy from temp to arr, other O(N) for running loop to find cnt]
// Space Complexity: O(N)