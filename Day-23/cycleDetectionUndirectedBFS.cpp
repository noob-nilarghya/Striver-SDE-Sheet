#include <bits/stdc++.h>

bool detection(int start, int parent, vector<int>* adj, vector<bool>& isVisited){
    queue<pair<int,int>> q;
    q.push({start, -1});  isVisited[start]=true;
    
    while(!q.empty()){
        pair<int, int> p=q.front(); q.pop();
        int node=p.first; int parent=p.second;
        
        for(int i=0; i<adj[node].size(); i++){
            int baccha=adj[node][i];
            if(isVisited[baccha]==true && baccha != parent){
                return true;
            }
            else if(isVisited[baccha]==false){
                q.push({baccha, node});
                isVisited[baccha]=true;
            }
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
