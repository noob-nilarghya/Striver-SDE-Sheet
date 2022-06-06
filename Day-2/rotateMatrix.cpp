#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int m, int n){
    int len=m; int width=n;
    m--; n--; int start=0; // 0-based indexing init
    
    while( len>1 && width>1 ){
        int row=start; int col=n; // upper right
        int val=mat[row][col]; // upper right original value
        
        while(col>start){ // going left <-----
            mat[row][col]=mat[row][col-1];
            col--;
        }
        if(row==start && col==start){ // upper left
            mat[row][col]=mat[row+1][col];
        }
        row++;
        while(row<m){ // going down
            mat[row][col]=mat[row+1][col];
            row++;
        }
        if(row==m && col==start){ // lower left
            mat[row][col]=mat[row][col+1];
        }
        col++;
        while(col<n){ // going right --->
            mat[row][col]=mat[row][col+1];
            col++;
        }
        if(row==m && col==n){ // lower right
            mat[row][col]=mat[row-1][col];
        }
        row--;
        while(row>start){ // goint up
            mat[row][col]=mat[row-1][col];
            row--;
        }
        if(row==start && col==n){ // again reached to upper right
            // make value of upper right as value of grid just below upper right (rotation)
            mat[row+1][col]=val; 
        }
        m--; n--; start++;
        len-=2; width-=2; // length decrease by 2 (-- from UP, -- from DOWN)
                          // width  decrease by 2 (--from left, --from right)
    }
}

// Time Complexity: O(m*n)
// Space Complexity: O(1)