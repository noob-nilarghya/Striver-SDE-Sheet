#include <bits/stdc++.h>

vector<int> NGL(vector<int>& price, int dummyMinIdx){
    vector<int> ans; stack<int> s;
    for(int i=0; i<price.size(); i++){
        if(s.empty()==true){
            ans.push_back(dummyMinIdx);
        }
        else if(price[s.top()] > price[i]){
            ans.push_back(s.top());
        }
        else if(price[s.top()] <= price[i]){
            while(!s.empty() && price[s.top()] <= price[i]){
                s.pop();
            }
            if(s.empty()==true){
                ans.push_back(dummyMinIdx);
            }
            else if(price[s.top()] > price[i]){
                ans.push_back(s.top());
            }
        }
        s.push(i);
    }
    return ans;
}

vector<int> findSpans(vector<int> &price) {
    vector<int> ngl= NGL(price, -1);
    vector<int> ans;
    for(int i=0; i<price.size(); i++){
        ans.push_back(i-ngl[i]);
    }
    return ans;
}