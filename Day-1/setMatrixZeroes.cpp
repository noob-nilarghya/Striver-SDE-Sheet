#include <bits/stdc++.h> 

void setMat(vector<vector<int>> &matrix,int i, int j, int m, int n){
    for(int row=0; row<matrix.size(); row++){  matrix[row][j]=0;  }
    for(int col=0; col<matrix[i].size(); col++){  matrix[i][col]=0;  }
}

void setZeros(vector<vector<int>> &matrix){
    vector<pair<int, int>> vec;
	for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            if(matrix[i][j]==0){
                vec.push_back({i,j});
            }
        }
    }
    for(int i=0; i<vec.size(); i++){
        int row=vec[i].first;  int col=vec[i].second;
        setMat(matrix, row, col, matrix.size(), matrix[row].size());
    }
}

// Time Complexity: O(m*n);
// Space Complexity: O(m*n);
/* Space can be optimized by creating 2 dummy array: row arr, col arr. When we get 0 (i,j), 
we put corresponding row & col in both array as 1 indicating row=rowArr[i], col=colArr[j]. ---> O(m+n) */