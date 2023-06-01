#include <bits/stdc++.h> 
#include <vector>

bool binarySearch(vector<vector<int>>& mat, int row, int low, int high, int target){
    if(low>high){ return false; }
    int mid= low+(high-low)/2;
    if(mat[row][mid]==target){ return true; }
    else if(mat[row][mid]>target){
        return binarySearch(mat, row, low, mid-1, target);
    }
    return binarySearch(mat, row, mid+1, high, target);
}

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int i=0; int row=mat.size(); int col=mat[0].size();
    while(i<row && mat[i][col-1]<target){
        i++;
    }
    if(i==row){ return false; }
    return binarySearch(mat, i, 0, col-1, target);
}

// Time Complexity: O(nlogn)
// Space Complexity: O(1)