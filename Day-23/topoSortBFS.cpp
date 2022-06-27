#include <bits/stdc++.h>
// Kahn's Algorithm [topo sort BFS]

vector<int> topologicalSort(vector<vector<int>> &edge, int v, int e)  {
    int vertex=v;
    
    vector<bool> isVisited(vertex, false);
    vector<int> adj[vertex];
    vector<int> inDeg(vertex, 0);
    
    for(int i=0; i<edge.size(); i++){
        int u=edge[i][0]; int v=edge[i][1];
        // That is [u --> v] edge. So inDeg[v]++;
        inDeg[v]++;
        adj[u].push_back(v);
    }
    // we have our inDegree ready. Now insert all the vertex in queue whose indegree is 0 & start the process
    queue<int> q;  
    for(int i=0; i<vertex; i++){
        if(inDeg[i]==0){
            q.push(i);
            isVisited[i]=true; // mark node visited as soon as we push vertex in queue
        }
    }
    vector<int> topoSort;
    
    while(!q.empty()){
        int front=q.front(); q.pop();
        topoSort.push_back(front);
        for(int i=0; i<adj[front].size(); i++){
            int baccha=adj[front][i];
            inDeg[baccha]--;
            if(inDeg[baccha]==0 && isVisited[baccha]==false){
                q.push(baccha);
                isVisited[baccha]==true;
            }
        }
    }
    
    return topoSort;
}