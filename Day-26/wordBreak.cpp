#include <bits/stdc++.h> 

bool helper(int idx, string& target, unordered_map<string, int>& m, vector<int>& dp){
    if(idx>=target.size()){ return true; }
    if(dp[idx]!=-1){ return dp[idx]; }
    string temp="";
    for(int i=idx; i<target.size(); i++){
        temp.push_back(target[i]);
        if(m.count(temp)>0){
            bool tempAns= helper(i+1, target, m, dp);
            if(tempAns==true){ return dp[idx]=true; }
        }
    }
    return dp[idx]=false;
}

bool wordBreak(vector<string>& arr, int n, string & target) {
    unordered_map<string, int> m;
    for(int i=0; i<arr.size(); i++){
        m[arr[i]]++;
    }
    vector<int> dp(target.size()+1, -1);
    return helper(0, target, m, dp);
}