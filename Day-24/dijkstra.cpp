    vector <int> dijkstra(int vertices, vector<vector<int>> adj[], int source){
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // minHeap
        vector<int> dist(vertices, INT_MAX); vector<bool> isVisited(vertices, false);

        dist[source]=0; isVisited[source]=true;
        for(int i=0; i<adj[source].size(); i++){
            int v=adj[source][i][0]; int wt=adj[source][i][1];
            dist[v]=wt;
            pq.push({dist[v], v});
        }
        
        while(!pq.empty()){
            pair<int, int> front=pq.top(); pq.pop();
            int node=front.second; int distance=front.first; isVisited[node]=true;
            for(int i=0; i<adj[node].size(); i++){
                int v=adj[node][i][0]; int edgeWt=adj[node][i][1];
                int prevDist=dist[v];
                if(isVisited[v]==false && prevDist > (distance+edgeWt)){
                    dist[v]=distance+edgeWt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }