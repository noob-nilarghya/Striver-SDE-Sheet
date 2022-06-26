#include <bits/stdc++.h>

class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    Kthlargest(int k, vector<int> &arr) {
       for(int i=0; i<k; i++){
           pq.push(arr[i]);
       }
        for(int i=k; i<arr.size(); i++){
            if(pq.top() < arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    

    void add(int num) {
        if(pq.top() < num){
            pq.pop();
            pq.push(num);
        }
    }

    int getKthLargest() {
       return pq.top();
    }

};