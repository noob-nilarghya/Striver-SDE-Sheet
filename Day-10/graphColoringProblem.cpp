bool helper(int start, vector<vector<int>>& mat, int m, vector<int>& colArr){
    if(start==mat.size()){ return true; }
    for(int col=1; col<=m; col++){
        // check for all its adjecent node & check that wheather any of the node is colured with col
        int canI=1;
        for(int i=0; i<mat.size(); i++){
            if(i==start){ continue; }
            if(mat[start][i]==1 && colArr[i]==col){ // i is adjecnt node of start & colored with col
                canI=0;  break; // so I cant color start with col, so I break loop & try with next col
            }
        }
        if(canI==1){ // no adjecent node is coloured with col, so I can color start with col
            colArr[start]=col;
            bool a= helper(start+1, mat, m, colArr);
            if(a==true){ return true; }
            colArr[start]=-1; // backtrack
        }
        //else try with next color
    }
    // I can color the node with no color from [1-m], so return false
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    vector<int> colArr(mat.size(), -1);
    int a=helper(0, mat, m, colArr);
    if(a==true){ return "YES"; }
    return "NO";
}