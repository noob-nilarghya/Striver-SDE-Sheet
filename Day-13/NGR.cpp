#include <bits/stdc++.h>

vector<int> nextGreater(vector<int> &arr, int n) {
    vector<int> ans;
    stack<int> s;
    for(int i=n-1; i>=0; i--){
        if(s.empty()==true){
            ans.push_back(-1);
        }
        else if(s.top() > arr[i]){ // yep ! we got our NGR
            ans.push_back(s.top());
        }
        else if(s.top() <= arr[i]){
            // pop ele from stack until s.top() > arr[i]
            while(!s.empty() && s.top() <= arr[i]){
                s.pop();
            }
            if(s.empty()==true){ // No NGR found
                ans.push_back(-1);
            }
            else if(s.top() > arr[i]){
                ans.push_back(s.top());
            }
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}