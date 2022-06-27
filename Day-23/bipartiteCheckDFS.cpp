
bool checkDFS(int start, vector<vector<int>> &edge, vector<int>& color, int currCol, int vertex){
    color[start]=currCol;
    if(currCol==1){ currCol=2; }
    else if(currCol==2){ currCol=1; }
    
    for(int i=0; i<vertex; i++){
        if(edge[start][i]==1){ // edge exist
            if(color[i]==0){ // no color has assigned
                int a= checkDFS(i, edge, color, currCol, vertex);
                if(a==false){ return false; }
            }
            else if(color[i]!=currCol){
                return false;
            }
        }
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edge) {
    int vertex=edge.size();
	vector<int> color(vertex, 0);
    for(int i=0; i<vertex; i++){
        for(int j=0; j<vertex; j++){
            if(edge[i][j]==1){
                edge[j][i]=1;
            }
        }
    }
    
    for(int i=0; i<vertex; i++){
        if(color[i]==0){
            bool a=checkDFS(i, edge, color, 1, vertex);
            // 1-denotes color BLUE, 2-denotes color GREEN, 0-denotes no color assigned(or not visited)
            if(a==false){
                return false;
            }
        }
    }
    return true;
}