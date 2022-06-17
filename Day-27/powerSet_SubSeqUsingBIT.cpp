// This is the way how we generate power set (all possible sub-sequence) using BIT MANUPULATION

vector<vector<int>> pwset(vector<int>v){
    int size=v.size();
    int num=(int)(pow(2, size)+0.5); vector<vector<int>> ans;
    
    for(int i=0; i<num; i++){
        vector<int> vec;
        for(int idx=0; idx<size; idx++){
            if( (i&(1<<idx)) != 0){ // (idx)th bit of i is set
                vec.push_back(v[idx]);
            }
        }
        ans.push_back(vec);
    }
    return ans;
}