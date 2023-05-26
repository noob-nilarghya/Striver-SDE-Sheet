#include <bits/stdc++.h>

string intToString(int k){   stringstream nil;   nil<<k;   string s;  nil>>s;  return s;  }

string writeAsYouSpeak(int n){
    if(n==1){
        return "1";
    }
    string temp=writeAsYouSpeak(n-1); string ans=""; int idx=0;

    while(idx<temp.size()){ 
        char c=temp[idx]; int cnt=0;
        while(idx<temp.size() && temp[idx]==c){
            idx++;
            cnt++;
        }
        string a= intToString(cnt); ans+=a;
        ans.push_back(c);
    }
    return ans;
}
