#include <bits/stdc++.h>

vector<int> KMostFrequent(int n, int k, vector<int> &arr){
    unordered_map<int, int> m;
    for(auto it: arr){
        m[it]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq; // max PQ
    for(auto it= m.begin(); it!=m.end(); it++){
        pq.push({(*it).second, (*it).first});
    }
    vector<int> ans;
    while(k--){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}