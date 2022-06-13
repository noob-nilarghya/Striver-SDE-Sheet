// Basically partition at every possible index & pass the rest of the string to recursion
// For any partion position, if substring is present in words & recursion return true --> Return true
// Here we can apply DP, because IF WE FOUND A WAY, we immediately return true & TERMINATE OUR PROCESS
// But if we have to go through all the path (even after finding a valid path), then we need BACKTRACKING (WordBreak2)

//---------------------------------------------------------------------------------------------------------------------
    //BRUTEFORCE : 
    bool helper(string s, int idx, int size, unordered_map<string, int>& m){
        if(idx==size){
            return true;
        }
        for(int i=idx; i<size; i++){ // i will be our partition index
            
            string temp=s.substr(idx, i-idx+1);
            if(m.count(temp)>0){ // segmented part is present in map
                bool a= helper(s, i+1, size, m);
                if(a==true){ return true; }
            }
        }
        return false; // no partition point found
    }
    
    bool wordBreak(string s, vector<string>& word) {
        unordered_map<string, int> m;
        for(int i=0; i<word.size(); i++){
            m[word[i]]++;
        }
        bool a= helper(s,0,s.length(),m);
        return a;
    }
//--------------------------------------------------------------------------------------------------------------------

    // MEMOIZATION: 
    bool helper(string s, int idx, int size, unordered_map<string, int>& m, vector<int>& dp){
        if(idx==size){
            return true;
        }
        if(dp[idx] !=-1){
            if(dp[idx]==0){ return false; }
            return true;
        }
        for(int i=idx; i<size; i++){ // i will be our partition index
            
            string temp=s.substr(idx, i-idx+1);
            if(m.count(temp)>0){ // segmented part is present in map
                bool a= helper(s, i+1, size, m, dp);
                if(a==true){
                    dp[idx]=1;
                    return true; 
                }
            }
        }
        dp[idx]=0;
        return false; // no partition point found
    }
    
    bool wordBreak(string s, vector<string>& word) {
        unordered_map<string, int> m;
        for(int i=0; i<word.size(); i++){
            m[word[i]]++;
        }
        vector<int> dp(s.length()+1, -1);
        bool a= helper(s,0,s.length(),m, dp);
        return a;
    }