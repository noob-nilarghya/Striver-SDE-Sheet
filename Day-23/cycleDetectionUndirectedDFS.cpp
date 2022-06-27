
bool detection(int start, int parent, vector<int>* adj, vector<bool>& isVisited){
    isVisited[start]=true;
    for(int i=0; i<adj[start].size(); i++){
        int baccha=adj[start][i];
        if(isVisited[baccha]==true && baccha != parent){
            return true;
        }
        else if(isVisited[baccha]==false){
            bool a= detection(baccha, start, adj, isVisited);
            if(a==true){ return true; }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edge, int n, int m){
    int vertex=n; int e=m; 
    vector<int> adj[vertex+1];
    for(int i=0; i<e; i++){
        int u=edge[i][0]; int v=edge[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> isVisited(vertex+1, false);
    for(int i=1; i<=vertex; i++){
        if(isVisited[i]==false){
            bool a= detection(i, -1, adj, isVisited);
            if(a==true){ return "Yes"; }
        }
    }
    return "No";
}
