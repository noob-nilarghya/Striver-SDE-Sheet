#include <bits/stdc++.h>

bool checkBFS(int start, vector<vector<int>> &edge, vector<int>& color, int Col, int vertex){
    queue<int> q;
    q.push(start);  color[start]=Col;
    
    while(!q.empty()){
        int front=q.front(); q.pop();
        int currCol= color[front];
        if(currCol==1){ currCol=2; }
        else if(currCol==2){ currCol=1; }
        
        for(int i=0; i<vertex; i++){
            if(edge[front][i]==1){ // edge existed
                if(color[i]==0){ // no color assigned (not visited)
                    color[i]=currCol;
                    q.push(i);
                }
                else if(color[i]!=currCol){
                    return false;
                }
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
            bool a=checkBFS(i, edge, color, 1, vertex);
            // 1-denotes color BLUE, 2-denotes color GREEN, 0-denotes no color assigned(or not visited)
            if(a==false){
                return false;
            }
        }
    }
    return true;
}