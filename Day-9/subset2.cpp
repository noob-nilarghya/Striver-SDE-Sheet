#include <bits/stdc++.h>

void helper(vector<int>& arr, int idx, int n, vector<int>& temp, set<vector<int>>& st){
    if(idx==n){
        vector<int> vec(temp);
        sort(vec.begin(), vec.end());
        st.insert(vec);
        return;
    }
    temp.push_back(arr[idx]);
    helper(arr, idx+1, n, temp, st);
    temp.pop_back();
    helper(arr, idx+1, n, temp, st);
    return;
}

//-------------------------------------------------------------------------------------------------

void helperOptimized(vector<vector<int>>& ans, vector<int>& arr, int idx, int n, vector<int>& temp){
    ans.push_back(temp);
    for(int i=idx; i<n; i++){
        if(i!=idx && arr[i-1]==arr[i]){ continue; }
        temp.push_back(arr[i]);
        helperOptimized(ans, arr, i+1, n, temp); // ALWAYS INSERTION
        temp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> temp; set<vector<int>> st;
    helper(arr, 0, arr.size(), temp, st);
    
    //-----------------------------------------------------------
    
    sort(arr.begin(), arr.end()); // MOST IMP STEP
    helperOptimized(ans, arr, 0, arr.size(), temp); // No need of set (as we will avoid duplicate values)
    
    for(auto it=st.begin(); it!=st.end(); it++){
        ans.push_back((*it));
    }
    return ans;
}

// Time Complexity: O( 2^n *[(n log n)+ (n log x)]).
// Space Complexity: O(2^n * n)


