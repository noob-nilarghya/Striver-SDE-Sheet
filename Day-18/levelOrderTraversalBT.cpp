
vector<int> getLevelOrder(BinaryTreeNode<int>* root){
    vector<int> ans;
    if(root==NULL){ return ans; }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front(); q.pop();
        ans.push_back((*front).val);
        
        if((*front).left != NULL){
            q.push((*front).left);
        }
        if((*front).right != NULL){
            q.push((*front).right);
        }
    }
    return ans;
}
