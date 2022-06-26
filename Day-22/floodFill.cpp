#include <bits/stdc++.h>
// Similar (close to exactly same) to Rotten Oranges

bool validIdx(int x, int y, int m, int n){
    if(x<0 || x>m-1 || y<0 || y>n-1){
        return false;
    }
    return true;
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor){
    int oldColor=image[x][y]; int m=image.size(); int n=image[0].size();

    if(newColor==oldColor){ return image; } // no need to change anything [VERY VERY IMP EDGE CASE]
    // Otherwise we may encounter infinite loop as we rae not maintaining isVisited & relying on grid color value
    
    queue<pair<int, int>> q;
    q.push({x,y}); image[x][y]=newColor;
    
    while(!q.empty()){
        
        pair<int, int> p=q.front(); q.pop();
        int r=p.first; int c=p.second;
        
        if(validIdx(r+1,c,m,n)==true && image[r+1][c]==oldColor){ // down
            q.push({r+1,c});
            image[r+1][c]=newColor;
        }
        if(validIdx(r-1,c,m,n)==true && image[r-1][c]==oldColor){ // up
            q.push({r-1,c});
            image[r-1][c]=newColor;
        }
        if(validIdx(r,c+1,m,n)==true && image[r][c+1]==oldColor){ // right
            q.push({r,c+1});
            image[r][c+1]=newColor;
        }
        if(validIdx(r,c-1,m,n)==true && image[r][c-1]==oldColor){ // left
            q.push({r,c-1});
            image[r][c-1]=newColor;
        }
    }
    return image;
}