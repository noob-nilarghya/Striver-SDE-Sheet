#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
	priority_queue<int, vector<int>> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
    
    vector<int> ans;
    maxPQ.push(arr[0]); ans.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(maxPQ.top()> arr[i]){
            maxPQ.push(arr[i]);
        }
        else{ minPQ.push(arr[i]); }
        
        if(maxPQ.size()==minPQ.size()){
            ans.push_back( (maxPQ.top()+minPQ.top())/2 );
        }
        else if(maxPQ.size()-minPQ.size()==1){
            ans.push_back( maxPQ.top() );
        }
        else if(minPQ.size()-maxPQ.size()==1){
            ans.push_back( minPQ.top() );
        }
        else if(maxPQ.size()-minPQ.size()==2){
            minPQ.push(maxPQ.top()); maxPQ.pop();
            ans.push_back( (maxPQ.top()+minPQ.top())/2 );
        }
        else if(minPQ.size()-maxPQ.size()==2){
            maxPQ.push(minPQ.top()); minPQ.pop();
            ans.push_back( (maxPQ.top()+minPQ.top())/2 );
        }
    }
    return ans;
}
