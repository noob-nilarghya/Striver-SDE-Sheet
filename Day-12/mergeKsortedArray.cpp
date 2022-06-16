#include <bits/stdc++.h>

vector<int> mergeKSortedArrays(vector<vector<int>>&KArrays, int k){
    // minHeap store pair of {elemnt, array Number from which element belongs}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minPQ;
    for(int i=0; i<k; i++){
        minPQ.push({KArrays[i][0], i}); // insert all the first element
    }
    vector<int> vec(k, 0); // index--> arrayNumber [0,k-1]
                           // value at Index --> last index of (index)th array that was pushed in minPQ
    vector<int> ans;
    while(!minPQ.empty()){
        pair<int, int> p= minPQ.top(); minPQ.pop();
        ans.push_back(p.first);
        int arrNumber=p.second; int idxToBeInserted= vec[arrNumber]+1; int size=KArrays[arrNumber].size();
        if(idxToBeInserted <= size-1){
            minPQ.push({KArrays[arrNumber][idxToBeInserted], arrNumber}); 
            // push the next ele from the same array (of whose value has been removed)
            vec[arrNumber]=idxToBeInserted; // update the last index of arrNum in vec
        }
    }
    return ans;
}
