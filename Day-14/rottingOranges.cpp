#include <bits/stdc++.h>
// BFS --> Similar to level order traversal
// Here we can't apply DFS as we are not required to go till deep in one direction ans come back & then go to another direction (till deep) 
// But here we are required to go to all direction from particular grid & rotten it SIMULTANOUSLY (in which BFS has mastery)

int minTimeToRot(vector<vector<int>>& grid, int m, int n){
    queue<pair<int,int>> q; int day=0; int totalOrange=0; int cnt=0; // at end if (totalOrange==cnt) 0> all orange have rotten
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1 || grid[i][j]==2){ totalOrange++; }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==2){
                q.push({i,j}); // insert all the rotten orange of day 0
                cnt++;
            }
        }
    }
    q.push({-1,-1}); // just to indiacate the end of the day

    while(!q.empty()){
        pair<int, int> p=q.front(); q.pop();
        if(p.first==-1 && p.second==-1){ // end of day 
            q.push({-1,-1});
            if(q.size()==1){ // no more rotten orange in queue. break loop
                break;
            }
            day++; // go to next day
        }
        else{
            // go and travel all possible 4 directions
            int row=p.first; int col=p.second; 
            if(row+1>=0 && row+1<=m-1 && col>=0 && col<=n-1){ // valid down index
                if(grid[row+1][col]==1){ // as we will not go in empty or already rotten cell
                    q.push({row+1, col});
                    grid[row+1][col]=2;
                    cnt++;
                }
            }
            if(row-1>=0 && row-1<=m-1 && col>=0 && col<=n-1){ // valid up index
                if(grid[row-1][col]==1){ // as we will not go in empty or already rotten cell
                    q.push({row-1, col});
                    grid[row-1][col]=2;
                    cnt++;
                }
            }
            if(row>=0 && row<=m-1 && col+1>=0 && col+1<=n-1){ // valid right index
                if(grid[row][col+1]==1){ // as we will not go in empty or already rotten cell
                    q.push({row, col+1});
                    grid[row][col+1]=2;
                    cnt++;
                }
            }
            if(row>=0 && row<=m-1 && col-1>=0 && col-1<=n-1){ // valid left index
                if(grid[row][col-1]==1){ // as we will not go in empty or already rotten cell
                    q.push({row, col-1});
                    grid[row][col-1]=2;
                    cnt++;
                }
            }
        }
    }
    if(cnt==totalOrange){
        return day;
    }
    return -1;
}