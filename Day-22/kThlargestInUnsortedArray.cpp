#include <bits/stdc++.h>

int kthLargest(vector<int>& arr, int size, int k){
	priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }
    for(int i=k; i<size; i++){
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}