#include <bits/stdc++.h> 
// as we need to merge, early starting intervals should come first

bool comparator(vector<int>& v1, vector<int>& v2){ // so sort by start value
    return v1[0]<v2[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    if(intervals.size()==0 || intervals.size()==1){
        return intervals;
    }
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), comparator);
    int start=intervals[0][0];
    int end= intervals[0][1];
    
    for(int i=1; i<intervals.size(); i++){
        int low= intervals[i][0];
        int high=intervals[i][1];
        
        if(end>=low){ // overlapped
            start= min(start, low);
            end= max(end, high);
        }
        else{ // not overlapped
            vector<int> vec; vec.push_back(start); vec.push_back(end); ans.push_back(vec);
            start=low; end=high; // update
        }
    }
    vector<int> vec; vec.push_back(start); vec.push_back(end);
    ans.push_back(vec); return ans;
}
