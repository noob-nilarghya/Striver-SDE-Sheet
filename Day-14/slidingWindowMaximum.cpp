#include <bits/stdc++.h>

vector<int> slidingWindowMaximum(vector<int> &nums, int &k){
    int i=0; int j=0; vector<int> ans; list<int> ls;
    
    while(j<nums.size()){
        // calculation for jth index
        while(!ls.empty() && ls.back() < nums[j]){
            ls.pop_back();
        }
        ls.push_back(nums[j]);
        if((j-i+1) <k){
            j++;
        }
        else if((j-i+1) == k){
            // do calculation for current window
            ans.push_back(ls.front());
            // Undo calculation for ith index
            if(nums[i] == ls.front()){
                ls.pop_front();
            }
            i++; j++; //maintain window;
        }
    }
    return ans;
}