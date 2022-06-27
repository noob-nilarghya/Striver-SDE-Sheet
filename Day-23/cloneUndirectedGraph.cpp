//                       [ VERY VERY IMPORTANT ]

graphNode *cloneGraph(graphNode* node){
    if(node==NULL){ return NULL; }

    unordered_map<graphNode*, bool> isVisited;  // visited map
    unordered_map<graphNode*, graphNode*> match;  // match original node (key) with copied node (value)
    queue<graphNode*> q;
    graphNode* root= new graphNode((*node).data);  // create deep copy of node
    match[node]=root; isVisited[node]=true;
    q.push(node);
    
    while(!q.empty()){
        graphNode* org=q.front(); q.pop();
        graphNode* cpy=match[org];
        
        vector<graphNode*> v=(*org).neighbours;
        for(int i=0; i<v.size(); i++){
            graphNode* baccha= v[i];
            
            if(isVisited.count(baccha)==0){ // baccha is not visited till now
                // make a naccha copy node
                // match baccha with baccha copy, make baccha visited
                // make baccha copy as baccha of cpy
                // push baccha in queue
                graphNode* bacchaCopy= new graphNode((*baccha).data);
                match[baccha]=bacchaCopy;  isVisited[baccha]=true;
                (*cpy).neighbours.push_back(bacchaCopy);
                q.push(baccha);
            }
            else if(isVisited.count(baccha)>0){ // baccha is already visited
                // As baccha is visited, so its match is definately present
                // fetch its match (let it be bacchaCpy)
                // make bacchaCpy as baccha of cpy
                // do not push in queue (as baccha is already visited)
                graphNode* bacchaCpy= match[baccha];
                (*cpy).neighbours.push_back(bacchaCpy);
            }
        }
    }
    return root;
}