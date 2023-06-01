vector<int> ans;

void helper(vector<int>& num, int idx, int n, int sum){
    if(idx==n){
        ans.push_back(sum);
        return;
    }
    helper(num, idx+1, n, sum+num[idx]);
    helper(num, idx+1, n, sum);
    return;
}

vector<int> subsetSum(vector<int> &num){
    ans.clear();
    helper(num, 0, num.size(), 0);
    sort(ans.begin(), ans.end());
    return ans;
}

// Time Complexity: O(2^n) + O(2^nlog2^n)
// Space Complexity: O(2^n)