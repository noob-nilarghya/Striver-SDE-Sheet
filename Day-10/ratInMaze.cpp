vector<vector<int>> ans;

void helper(vector<vector<int>>& maze, vector<vector<int>>& board, int row, int col, int n){
    if(row==n-1 && col==n-1){
        board[row][col]=1;
        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        board[row][col]=0; // backtrack
        return;
    }
    
    if(row<0 || row>n-1 || col<0 || col>n-1 || maze[row][col]==0 || board[row][col]==1){
        return;  // row & col should be in bound, I should not step over obstacle and, I should not visit already visited cell again
    }
    
    board[row][col]=1; // I mark this cell as visited & now I explore every possible path from here
    helper(maze, board, row+1, col, n);
    helper(maze, board, row-1, col, n);
    helper(maze, board, row, col+1, n);
    helper(maze, board, row, col-1, n);
    board[row][col]=0; // backtrack
    return;
}

vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    ans.clear();
    vector<vector<int>> board(n, vector<int>(n, 0)); // initially no grid has been visited
    helper(maze, board, 0, 0, n);
    return ans;
}