#include <bits/stdc++.h>

class unionFind{
    int* parent;
    int* rank;
    public:
    unionFind(int vertex){
        parent= new int[vertex+1];
        rank= new int[vertex+1];
        for(int i=0; i<=vertex; i++){
            parent[i]=i; // initially all nodes is parent of itself
            rank[i]=0; // initially all node has rank 0
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node; 
        }
        parent[node]=findParent(parent[node]); // path compression
        return parent[node];
    }
    void unionNode(int u, int v){
        int par1=findParent(u);
        int par2=findParent(v);
        if(par1 == par2){ return; } // they belongs to same connected componenent
        
        if(rank[par1] == rank[par2]){
            parent[par2]=par1;
            rank[par1]++;
        }
        else if(rank[par1] > rank[par2]){
            parent[par2]=par1;
        }
        else if(rank[par1] < rank[par2]){
            parent[par1]=par2;
        }
        return;
    }
};

static bool comparator(vector<int>& v1, vector<int>& v2){
    return v1[2]<v2[2];
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    int vertex=n; int edge=m;
	sort(graph.begin(), graph.end(), comparator); // sort edges in incresing order of weight
    unionFind uf(vertex);
    
    int MSTedge=vertex-1;
    int mstWeight=0; int cnt=0;
    for(int i=0; i<edge; i++){
        int u=graph[i][0]; int v=graph[i][1]; int wt=graph[i][2];
        int par1=uf.findParent(u);  int par2=uf.findParent(v);
        
        if(par1 != par2){ // they belongs to separate components
            uf.unionNode(u,v);
            mstWeight+=wt; cnt++;
            if(cnt==MSTedge){ return mstWeight; }
        }
    }
    return 0; //  just for the sake of returning something
}
