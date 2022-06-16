#include <bits/stdc++.h>

void findMedian(int *arr, int n){
    priority_queue<int, vector<int>> maxPQ; // store min ele
    priority_queue<int, vector<int>, greater<int>> minPQ; // store max ele
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        if(maxPQ.size()==0 && minPQ.size()==0){ // edge case, don't hard code before loop
            maxPQ.push(arr[i]);
            ans.push_back(arr[i]);
        }
        else{
            if(arr[i] <= maxPQ.top()){
                maxPQ.push(arr[i]);
            }
            else{
                minPQ.push(arr[i]);
            }

            if(maxPQ.size()-minPQ.size()==1){
                ans.push_back(maxPQ.top());
            }
            else if(minPQ.size()-maxPQ.size()==1){
                ans.push_back(minPQ.top());
            }
            else if(maxPQ.size()==minPQ.size()){
                ans.push_back((maxPQ.top()+minPQ.top())/2);
            }
            else if(maxPQ.size()-minPQ.size()==2){
                int ele= maxPQ.top(); maxPQ.pop(); minPQ.push(ele);
                ans.push_back((maxPQ.top()+minPQ.top())/2);
            }
            else if(minPQ.size()-maxPQ.size()==2){
                int ele= minPQ.top(); minPQ.pop(); maxPQ.push(ele);
                ans.push_back((maxPQ.top()+minPQ.top())/2);
            }
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}