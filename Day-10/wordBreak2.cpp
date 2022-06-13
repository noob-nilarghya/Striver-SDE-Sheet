#include <bits/stdc++.h>
// Pure Backtracking Approach: (As we have to return every sentence, so DP is not the option)

vector<string> ans;
void helper(string s, int idx, int size, unordered_map<string, int>& m, vector<string>& vec){
    if(idx==size){
        string s="";
        for(int i=0; i<vec.size(); i++){
            s+=vec[i];
            s+=" ";
        }
        ans.push_back(s);
        return;
    }
    for(int i=idx; i<size; i++){
        string temp=s.substr(idx, i-idx+1);
        if(m.count(temp)>0){ // segmented string found in words
            vec.push_back(temp);
            helper(s, i+1, size, m, vec);
            vec.pop_back(); // backtrack
        }
    }
    return;
}
vector<string> wordBreak(string &s, vector<string>& word){
    ans.clear();
    vector<string> vec;
    unordered_map<string, int> m;
    for(int i=0; i<word.size(); i++){
        m[word[i]]++;
    }
    helper(s,0,s.length(),m,vec);
    return ans;
}