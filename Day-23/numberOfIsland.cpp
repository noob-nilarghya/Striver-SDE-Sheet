void dfs(int** arr, int i, int j, int row, int col, vector<vector<bool>>& isVisited){
    if(i<0 || i>row-1 || j<0 || j>col-1 || arr[i][j]==0 || isVisited[i][j]==true){  return;  }
    
    isVisited[i][j]=true;
    dfs(arr, i+1, j, row, col, isVisited);
    dfs(arr, i, j+1, row, col, isVisited);
    dfs(arr, i-1, j, row, col, isVisited);
    dfs(arr, i, j-1, row, col, isVisited);
    dfs(arr, i+1, j+1, row, col, isVisited);
    dfs(arr, i+1, j-1, row, col, isVisited);
    dfs(arr, i-1, j+1, row, col, isVisited);
    dfs(arr, i-1, j-1, row, col, isVisited);
    return;
}

int getTotalIslands(int** arr, int m, int n) {
    vector<vector<bool>> isVisited(m+1, vector<bool>(n+1, false));
    int cnt=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==1 && isVisited[i][j]==false){
                cnt++;
                dfs(arr, i, j, m, n, isVisited);
            }
        }
    }
    return cnt;
}
