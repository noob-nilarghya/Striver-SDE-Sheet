vector<vector<int>> ans;

void helper(vector<int>& arr, vector<int>& temp, int idx, int n, int k){
    if(idx==n){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        return;
    }
    /*
    if(k==0){
        ans.push_back(temp);
        return;
    }
    if(idx==n && k!=0){ return; }
    // This base case WON'T WORK for : [5 -2 0 -5 2], target=0;
    */
    
    temp.push_back(arr[idx]);
    helper(arr, temp, idx+1, n, k-arr[idx]);
    temp.pop_back();
    helper(arr, temp, idx+1, n, k);
    return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int>& arr, int n, int k){
    ans.clear(); vector<int> temp;
    helper(arr, temp, 0, n, k);
    return ans;
}