vector<string> ans;
void helper(string input, string output){
    if(input.length()==0){
        ans.push_back(output);
        return;
    }
    for(int i=0; i<input.length(); i++){
        string ip=input; ip.erase(ip.begin()+i);
        helper(ip, output+input[i]);
    }
    return;
}
vector<string> findPermutations(string &s) {
    ans.clear();
    helper(s, "");
    return ans;
}

// Time Complexity: O(n!)
// Space Complexity: O((n+1)!)