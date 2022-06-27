#include <bits/stdc++.h>

void bfs(int start, vector<int>* adj, vector<bool>& isVisited, vector<int>& temp){
    queue<int> q;
    q.push(start);
    isVisited[start]=true; // mark node visited soon after pushing in queue
    
    while(!q.empty()){
        int front=q.front(); q.pop();
        temp.push_back(front);
        
        for(int i=0; i< adj[front].size(); i++){
            int baccha= adj[front][i];
            if(isVisited[baccha]==false){
                q.push(baccha);
                isVisited[baccha]=true;
            }
        }
    }
    return;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edge){
    vector<bool> isVisited(vertex, false);
    vector<int> adj[vertex];
    for(int i=0; i<edge.size(); i++){
        int u=edge[i].first; int v=edge[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<vertex; i++){
        vector<int> vec=adj[i]; 
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int> ans;
    for(int i=0; i<vertex; i++){
        if(isVisited[i]==false){
            bfs(i, adj, isVisited, ans);
        }
    }
    return ans;
}