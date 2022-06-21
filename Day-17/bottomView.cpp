
vector<int> bottomView(BinaryTreeNode<int> * root){
    if(root==NULL){ vector<int> vec; return vec; }
    
    // Perform simple level order traversal with little modification
    queue<pair<BinaryTreeNode<int>*, int>> q; // {node, vertical}
    map<int, int> m; // <vectical, nodeData>
    
    q.push({root, 0}); // as root is in vertical 0;
    while(!q.empty()){
        pair<BinaryTreeNode<int>*, int> p=q.front(); q.pop();
        int vertical=p.second; BinaryTreeNode<int>* front=p.first;
        m[vertical]=(*front).data; // AFTER POPPING from queue, UPDATE DATA ON MAP
        
        if((*front).left != NULL){
            q.push({(*front).left, vertical-1}); //as we are going to left, so vertical-1
        }
        if((*front).right != NULL){
            q.push({(*front).right, vertical+1}); // as we are going to right, so vertical+1
        }
    }
    vector<int> ans;
    for(auto it: m){
        ans.push_back(it.second);
    }
    return ans;
}

