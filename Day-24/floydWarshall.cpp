int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edge) {
    int vertex=n;

    vector<vector<int>> arr(vertex+1, vector<int>(vertex+1, INT_MAX));
    for(int i=1; i<=vertex; i++){
        arr[i][i]=0; // distance from me to myself is 0
    }
    for(int i=0; i<edge.size(); i++){
        int u=edge[i][0]; int v=edge[i][1]; int wt=edge[i][2];
        arr[u][v]=wt;
    }

    for(int k=1; k<=vertex; k++){  // including each vertex one by one
        for(int i=1; i<=vertex; i++){
            for(int j=1; j<=vertex; j++){
                // arr[i][j] = min( arr[i][j], arr[i][k]+arr[k][j] );
                if(arr[i][k]==INT_MAX || arr[k][j]==INT_MAX || i==k || j==k){
                    // distance won't get modified for k's adjecent verices(i==k || j==k) as including adject node won't affect dist
                    continue; 
                }
                else{
                    arr[i][j]=min(arr[i][j], arr[i][k]+arr[k][j]);
                }
            }
        }
    }
    if(arr[src][dest]==INT_MAX){
        return 1000000000;
    }
    return arr[src][dest];
}