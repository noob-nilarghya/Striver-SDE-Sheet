#include <bits/stdc++.h>

vector<int> kthSmallLarge(vector<int> &arr, int n, int k){
	priority_queue<int, vector<int>> maxPQ; // for min ele --> Kth min ele
    priority_queue<int, vector<int>, greater<int>> minPQ; // for max ele --> Kth max ele
    for(int i=0; i<k; i++){
        maxPQ.push(arr[i]);
        minPQ.push(arr[i]);
    }
    for(int i=k; i<n; i++){
        if(arr[i] < maxPQ.top()){
            maxPQ.pop();
            maxPQ.push(arr[i]);
        }
        if(arr[i] > minPQ.top()){
            minPQ.pop();
            minPQ.push(arr[i]);
        }
    }
    int small=maxPQ.top();  // Kth smallest
    int large= minPQ.top(); // Kth largest
    vector<int> ans; ans.push_back(small); ans.push_back(large);
    return ans;
}