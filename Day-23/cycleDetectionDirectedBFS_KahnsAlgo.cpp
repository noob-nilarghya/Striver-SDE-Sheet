#include <bits/stdc++.h>

/* Basically topo sort(DFS) or Kahn's algotithm(BFS), perform the same task. That is return topological sorted ordering of vertex. 
But both of the algorithm is successful in DAG. */
/* Here as we need to detect cycle in BFS fashion, so we will apply Kahn's Algo. 
    If Kahn's Algo fails, then we can conclude that this graph is not a DAG, hence this directed graph has cycle. 
    Else if Kahn's algorithm not fails, then we say that is a DAG (no cycle detected). */
// Basically this is nothing but " PROOF BY THE METHOD OF CONTRADICTION "

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> & edge) {
    int vertex=n;
    
    vector<bool> isVisited(vertex+1, false);
    vector<int> adj[vertex+1];
    vector<int> inDeg(vertex+1, 0);
    for(int i=0; i<edge.size(); i++){
        int u=edge[i].first; int v=edge[i].second;
        // That is [u --> v] edge. So inDeg[v]++;
        inDeg[v]++;
        adj[u].push_back(v);
    }
    // we have our inDegree ready. Now insert all the vertex in queue whose indegree is 0 & start the process
    queue<int> q;
    for(int i=1; i<=vertex; i++){
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
    
    if(topoSort.size()==vertex){ // Kahn's Algo succeeded. Hence it is a DAG --> No cycle detected
        return 0;
    }
    return 1; // cycle detected, as Kahn's Algo failed, it's not DAG
}