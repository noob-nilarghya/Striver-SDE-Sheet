int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edge) {
    int vertices=n;
    vector<int> dist(vertices+1, INT_MAX);
    
    dist[src]=0;
    for(int k=0; k<vertices-1; k++){ // relax all edges (vertices-1) times
        for(int i=0; i<edge.size(); i++){
            int u=edge[i][0]; int v=edge[i][1]; int wt=edge[i][2];
            // if( dist[v] > dist[u]+wt ) --> relaxation
            if(dist[u] != INT_MAX){
                if(dist[v] > dist[u]+wt){
                    dist[v]=dist[u]+wt;
                }
            }
        }
    }
    if(dist[dest]==INT_MAX){
        return 1000000000; // no distance found from source to destination
    }
    return dist[dest];
}