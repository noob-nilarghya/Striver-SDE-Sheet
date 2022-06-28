class Solution{
	public:
	
    int spanningTree(int V, vector<vector<int>> adj[]){
        
        vector<int> weight(V, INT_MAX); vector<int> parent(V, -1); vector<bool> isVisited(V, false);
        weight[0]=0; parent[0]=0; isVisited[0]=true;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // minHeap
        
        for(int i=0; i<adj[0].size(); i++){
            int v=adj[0][i][0]; int wt=adj[0][i][1];
            parent[v]=0; weight[v]=wt;
            pq.push({wt, v});
        }
        
        while(!pq.empty()){
            pair<int, int> top=pq.top(); pq.pop();
            int node=top.second; isVisited[node]=true;
            
            for(int i=0; i<adj[node].size(); i++){
                int v=adj[node][i][0]; int wt=adj[node][i][1];
                if(isVisited[v]==false && weight[v] > wt){
                    parent[v]=node;
                    weight[v]=wt;
                    pq.push({wt, v});
                }  
            }
        }
        int mstWt=0;
        for(int i=0; i<V; i++){
            mstWt+=weight[i];
        }
        return mstWt;
        
    }
};