#include <bits/stdc++.h>
// Same as "Minimum number of intervals to remove to make rest of the intervals NON-OVERLAPPING"

bool comparator(vector<int>& v1, vector<int>& v2){
    return v1[1]<v2[1]; // sort by endIndex
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<vector<int>> vec;
    for(int i=0;i <start.size(); i++){
        vector<int> temp={start[i], finish[i]};
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end(), comparator);   int cnt=1;
    int strt=vec[0][0];   int end=vec[0][1];
    for(int i=1; i<vec.size(); i++){ // element will come bt increasing end index
        int low=vec[i][0];
        int high=vec[i][1];
        
        if(low>=end){ // non-overlapping
            cnt++;
            end=max(end,high);
        }
    }
    return cnt;
}