// Problem of CodeStudio
// Intution came from: "Longest Sub-array Sum To K" + "Xor Query Sub-array" combined
#include <bits/stdc++.h> 

int subarraysXor(vector<int> &arr, int k){
    unordered_map<int, vector<int>> m; vector<int> temp;
    int Xor=0; int n=arr.size(); int cnt=0; m[Xor].push_back(0); temp.push_back(Xor);
    
    for(int i=0; i<n; i++){
        Xor=Xor^arr[i];
        m[Xor].push_back(i+1); temp.push_back(Xor);
    }
    
    for(int i=0; i<temp.size(); i++){
        int searching= temp[i]^k;
        if(m.count(searching)>0){
            int siz=m[searching].size();
            for(int idx=0; idx<siz; idx++){
                if(m[searching].at(idx)>i){ cnt++; }
            }
        }
    }
    return cnt;
}

// Time Complexity: O(n)
// Space Complexity: O(n)