#include <bits/stdc++.h>
vector<vector<int>> ans;
void helper(vector<int>& arr, int idx, int n, int target, vector<int>& vec){
    if(idx==n){
        if(target==0){
            ans.push_back(vec);
            return;
        }
        return;
    }
    
    vec.push_back(arr[idx]);
    helper(arr, idx+1, n, target-arr[idx], vec);
    vec.pop_back();
    helper(arr, idx+1, n, target, vec);
    return;
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    ans.clear();
	set<vector<int>> st;  vector<int> vec;
    helper(arr, 0, n, target, vec);
    // generated all subset sum to K (including duplicates). Now insert them in set one by one to get rid of duplicates
    for(int i=0; i<ans.size(); i++){
        vector<int> tmp=ans[i];
        sort(tmp.begin(), tmp.end());
        st.insert(tmp);
    }
    ans.clear();
    for(auto it=st.begin(); it!=st.end(); it++){
        ans.push_back((*it));
    }
    return ans;
}

//----------------------------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>

vector<vector<int>> ans;
void helper(vector<int>& arr, int idx, int n, int target, vector<int>& vec){
    if(target<0){ return; }
    if(target==0){
        ans.push_back(vec);
        return;
    }
    
    for(int i=idx; i<n; i++){
        if(idx!=i && arr[i-1]==arr[i]){ continue; }
        vec.push_back(arr[i]);
        helper(arr, i+1, n, target-arr[i], vec); // ALWAYS INSERTION
        vec.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
    ans.clear();
	sort(arr.begin(), arr.end()); // MOST IMP STEP
    vector<int> vec;
    helper(arr, 0, n, target, vec);
    return ans;
}

