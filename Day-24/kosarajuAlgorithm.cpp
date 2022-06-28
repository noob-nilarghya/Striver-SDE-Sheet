// This algorithm is used to find STRONGLY CONNECTED COMPONENT in a directed non-weighted graph
#include <bits/stdc++.h>

void DFS(int start, vector<int>* adj, vector<bool>& isVisited, stack<int>& s){
    isVisited[start]=true;
    for(int i=0; i<adj[start].size(); i++){
        int baccha=adj[start][i];
        if(isVisited[baccha]==false){
            DFS(baccha, adj, isVisited, s);
        }
    }
    s.push(start);
}

void reverse(vector<int>* adj, vector<int>* rev, int vertex){
    for(int i=0; i<vertex; i++){
        for(int j=0; j<adj[i].size(); j++){
            int u=i; int v=adj[i][j];
            rev[v].push_back(u);
        }
    }
}

void DFS2(int start, vector<int>* rev, vector<bool>& isVisited, vector<int>& vec){
    isVisited[start]=true;
    vec.push_back(start);
    for(int i=0; i<rev[start].size(); i++){
        int baccha=rev[start][i];
        if(isVisited[baccha]==false){
            DFS2(baccha, rev, isVisited, vec);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edge){
    int vertex=n;
    vector<int> adj[vertex]; vector<int> rev[vertex]; vector<bool> isVisited(vertex, false);
    stack<int> s;
    for(int i=0; i<edge.size(); i++){
        int u=edge[i][0]; int v=edge[i][1];
        adj[u].push_back(v);
    }
    
    for(int i=0; i<vertex; i++){ // call DFS to store nodes in stack
        if(isVisited[i]==false){
            DFS(i, adj, isVisited, s);
        }
    }
    reverse(adj, rev, vertex); // transpose the graph (reverse the edge direction)
    for(int i=0; i<vertex; i++){
        isVisited[i]=false; // reset all values to false
    }
    
    vector<vector<int>> ans; 
    while(!s.empty()){ // take out each node from stack, if unVisited, perform DFS2 with node as start
        int top=s.top(); s.pop();
        if(isVisited[top]==false){
            vector<int> vec;
            DFS2(top, rev, isVisited, vec);
            // Each successful DFS gives 1 SCC
            ans.push_back(vec);
        }
    }
    return ans;
}