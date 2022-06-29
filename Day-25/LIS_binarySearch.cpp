#include <bits/stdc++.h>

int binarySearch(vector<int>& temp, int target){ // lower bound in vector
    int low=0; int high=temp.size()-1; int potCand=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(temp[mid]==target){
            potCand=mid; // could be a potentialCandidate
            high=mid-1; // go left to find first occurance of ele (just like lower bound)
        }
        else if(temp[mid] > target){
            potCand=mid; // could be a potentialCandidate
            high=mid-1; // go left to go as close as TARGET as possible
        }
        else if(temp[mid] < target){
            low=mid+1; // go right to go as close as TARGET as possible
        }
    }
    return potCand;
}

int longestIncreasingSubsequence(int arr[], int n){
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(temp[temp.size()-1]<arr[i]){
            temp.push_back(arr[i]);
        }
        else if(temp[temp.size()-1] >= arr[i]){
            int pos= binarySearch(temp, arr[i]); // basically lower bound
            //int pos=lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[pos]=arr[i];
        }
    }
    // NOTE: temp is not LIS (even temp migh not be a sub-sequence also). 
    // We re just concerned about length of LIS (which is temp.size)
    return temp.size();
}