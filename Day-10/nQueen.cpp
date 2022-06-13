vector<vector<int>> ans;

bool isValid(int row, int col, int n, vector<vector<int>>& board){
    // check the col
    for(int i=0; i<row; i++){
        if(board[i][col]==1){ return false; }
    }
    // Check row
    for(int i=0; i<col; i++){
        if(board[row][i]==1){ return false; }
    }
    // check upper left diagonal
    int r1=row-1; int c1=col-1;
    while(r1>=0 && c1>=0){
        if(board[r1][c1]==1){ return false; }
        r1--; c1--;
    }
    // check upper right diagonal
    int r2=row-1; int c2=col+1;
    while(r2>=0 && c2<n){
        if(board[r2][c2]==1){ return false; }
        r2--; c2++;
    }
    return true;
}
void helper(int row, int n, vector<vector<int>>& board){
    if(row==n){ // no more queens to place. Valid board found
        vector<int> temp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        return;
    }
    for(int i=0; i<n; i++){
        if(isValid(row, i, n, board)==true){
            board[row][i]=1;
            helper(row+1, n, board);
            board[row][i]=0; // backtrack
        }
    }
    return;
}
vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    ans.clear(); 
    helper(0, n, board);
    return ans;
}