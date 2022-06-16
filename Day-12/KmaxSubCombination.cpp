// [ IMPORTANT ]
#include <bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	vector<int> ans;
    sort(a.begin(), a.end(), greater<int>());  sort(b.begin(), b.end(), greater<int>());
    priority_queue< pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>> > maxPQ;
    set<pair<int,int>> s; // To remove duplicacy
    maxPQ.push( {a[0]+b[0], {0,0}} ); s.insert({0,0});
    
    while(k){
        pair<int, pair<int,int>> p=maxPQ.top(); maxPQ.pop();
        ans.push_back(p.first); k--;
        int i=p.second.first;  int j=p.second.second;
        
        if(i+1<n){ // valid index
            if(s.find({i+1,j})==s.end()){ // This index combination {i+1, j} has not used before
                maxPQ.push({a[i+1]+b[j], {i+1,j}});   s.insert({i+1, j});
            }
        }
        if(j+1<n){ // valid index
            if(s.find({i,j+1})==s.end()){ // This index combination {i, j+1} has not used before
                maxPQ.push({a[i]+b[j+1], {i,j+1}});   s.insert({i, j+1});
            }
        }
    }
    return ans;
}