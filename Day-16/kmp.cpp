#include <bits/stdc++.h> 
vector<int> LPS(string str){
    int n= str.size();
    vector<int> lps(n, 0);

    int i=1; int len=0; // len will always be lps[i-1]
    while(i<n){
        if(str[i]==str[len]){ // char matched
            lps[i]=len+1;
            len++; i++;  // len is now  lps[i-1]
        }
        else{ // char mismatched
            if(len>0){
                len= lps[len-1];
            }
            else{ // len==0
                lps[i]=0;
                len=0; i++;  // len is now  lps[i-1]
            }
        }
    }
    return lps;
}

vector<int> kmpAlgo(string text, string pattern){
    string res="";
    res+=pattern;   res.push_back('#');   res+=text;
    vector<int> lps= LPS(res);

    int patLen=pattern.size(); 
    vector<int> ans;
    for(int i=0; i<lps.size(); i++){
        if(lps[i]==patLen){ // matching found and 'i' is last index of pattern
        	// but we have to store first index
            ans.push_back(i-patLen+1-patLen); // for 1-based indexing
        }
    }
    return ans;
}
bool findPattern(string p, string s){
    // Write your code here.
    vector<int> ans= kmpAlgo(s, p);
    return (ans.size()>0);
}