#include <bits/stdc++.h>
// This Question is same as "MINIMUM number of intervals to be removed to make rest of the intervals NON-OVERLAPPING"

bool comparator(vector<int>& v1, vector<int>& v2){
    // Acc To Qn: Also for the same end time, a meeting with a smaller index is preferred. 
    if(v1[1]==v2[1]){ 
        return v1[2]<v2[2];
    }
    return v1[1]<v2[1];
}

vector<int> maximumMeetings(vector<int> &Start, vector<int> &End) {
    vector<vector<int>> vec;
    for(int i=0; i<Start.size(); i++){
        vector<int> temp={Start[i],End[i],i};
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), comparator); vector<int> idx;
    int start=vec[0][0];
    int end=vec[0][1];
    idx.push_back(vec[0][2]+1);
    for(int i=1; i<vec.size(); i++){
        int low=vec[i][0];
        int high=vec[i][1];
       
        if(low> end){ // non-Overlapping
            idx.push_back(vec[i][2]+1);
            start=min(start, low);
            end=max(end, high);
        }
    }
    return idx;
}

// Time Complexity: O(N)+O(NlogN)
// Space Complexity: O(N)