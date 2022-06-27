void dfs(int start, vector<int>* adj, vector<bool>& isVisited, vector<int>& temp){
    isVisited[start]=true;
    temp.push_back(start);
    for(int i=0; i<adj[start].size(); i++){
        int baccha=adj[start][i];
        if(isVisited[baccha]==false){
            dfs(baccha, adj, isVisited, temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edge){
    vector<bool> isVisited(V, false);
    vector<int> adj[V];
    for(int i=0; i<E; i++){
        int u=edge[i][0]; int v=edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        if(isVisited[i]==false){
            vector<int> v; 
            dfs(i, adj, isVisited,v);
            ans.push_back(v);
        }
    }
    return ans;
}