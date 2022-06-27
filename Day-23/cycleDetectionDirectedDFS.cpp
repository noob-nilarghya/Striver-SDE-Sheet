
bool detect(int start, vector<int>* adj, vector<bool>& isVisited, vector<bool>& dfsVis){
    isVisited[start]=true;
    dfsVis[start]=true;
    for(int i=0; i<adj[start].size(); i++){
        int baccha= adj[start][i];
        
        if(isVisited[baccha]==false){ // perform normal dfs
            bool a= detect(baccha, adj, isVisited, dfsVis);
            if(a==true){ return true; }
        }
        else if(isVisited[baccha]=true && dfsVis[baccha]==true){
            return true;
        }
    }
    
    dfsVis[start]=false; // traversal of this path in dfs is OVER
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> & edge) {
    int vertex=n;
    vector<bool> isVisited(vertex+1, false);
    vector<bool> dfsVis(vertex+1, false);
    
    vector<int> adj[vertex+1];
    for(int i=0; i<edge.size(); i++){
        int u=edge[i].first; int v=edge[i].second;
        adj[u].push_back(v); // directed edge , so NO adj[v].psuh_back(u);
    }
    
    for(int i=1; i<=vertex; i++){
        if(isVisited[i]==false){
            bool a= detect(i, adj, isVisited, dfsVis);
            if(a==true){  return 1;  }
        }
    }
    return 0;
}