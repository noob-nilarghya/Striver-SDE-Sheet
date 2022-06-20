#include <bits/stdc++.h>

vector<int> NSR(vector<int>& height, int dummyMaxIdx) {
    stack<int> s; vector<int> ans;
    for(int i=height.size()-1; i>=0; i--){
        if(s.empty()==true){
            ans.push_back(dummyMaxIdx);
        }
        else if(height[s.top()] < height[i]){
            ans.push_back(s.top());
        }
        else if(height[s.top()] >= height[i]){
            while(!s.empty() && height[s.top()] >= height[i]){
                s.pop();
            }
            if(s.empty()==true){
                ans.push_back(dummyMaxIdx);
            }
            else if(height[s.top()] < height[i]){
                ans.push_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> NSL(vector<int>& height, int dummyMinIdx) {
    stack<int> s; vector<int> ans;
    for(int i=0; i<height.size(); i++){
        if(s.empty()==true){
            ans.push_back(dummyMinIdx);
        }
        else if(height[s.top()] < height[i]){
            ans.push_back(s.top());
        }
        else if(height[s.top()] >= height[i]){
            while(!s.empty() && height[s.top()] >= height[i]){
                s.pop();
            }
            if(s.empty()==true){
                ans.push_back(dummyMinIdx);
            }
            else if(height[s.top()] < height[i]){
                ans.push_back(s.top());
            }
        }
        s.push(i);
    }
    return ans;
}

int largestRectangle(vector<int>& height) {
    vector<int> nsr= NSR(height, height.size());
    vector<int> nsl= NSL(height, -1);
    int mx=INT_MIN;
    for(int i=0; i<height.size(); i++){
        int area=(nsr[i]-nsl[i]-1)*height[i];
        mx=max(mx,area);
    }
    return mx;
}