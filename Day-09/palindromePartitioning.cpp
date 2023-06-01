                                    // IMPORTANT \\
                                   //-------------\\

vector<vector<string>> ans;
bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start]!=s[end]){ return false; }
        start++; end--;
    }
    return true;
}
void helper(string s, int idx, int len, vector<string>& vec){
    if(idx==len){
        ans.push_back(vec);
        return;
    }
    for(int p=idx; p<len; p++){
        if(isPalindrome(s, idx, p)==true){
            vec.push_back(s.substr(idx, p-idx+1));
            helper(s, p+1, len, vec);
            vec.pop_back();
        }
    }
    return;
}
vector<vector<string>> partition(string &s) {
    ans.clear();
    vector<string> vec;
    helper(s, 0, s.length(), vec);
    return ans;
}