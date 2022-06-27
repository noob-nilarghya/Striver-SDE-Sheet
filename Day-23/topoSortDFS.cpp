#include <bits/stdc++.h>
void dfs(int start, vector<int>* adj, vector<bool>& isVisited, stack<int>& s){
    isVisited[start]=true;
    for(int i=0; i<adj[start].size(); i++){
        int baccha=adj[start][i];
        if(isVisited[baccha]==false){
            dfs(baccha, adj, isVisited, s);
        }
    }
    s.push(start);
    return;
}

vector<int> topologicalSort(vector<vector<int>> &edge, int vertex, int e)  {
    vector<bool> isVisited(vertex+1, false);
    vector<int> adj[vertex];
    for(int i=0; i<e; i++){
        int u=edge[i][0]; int v=edge[i][1];
        adj[u].push_back(v); // as [ u --> v ] 
    }
    vector<int> ans;  stack<int> s;
    
    for(int i=0; i<vertex; i++){
        if(isVisited[i]==false){
            dfs(i, adj, isVisited, s); 
        }
    }
    while(!s.empty()){ ans.push_back(s.top()); s.pop(); } //unload stack in vector after calling all connected components
    return ans;
}