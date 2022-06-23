
TreeNode<int>* helper(vector<int>& preOrder, int start, int end){
    if(start>end){ return NULL; }

    TreeNode<int>* newNode= new TreeNode<int>(preOrder[start]);
    int root= preOrder[start];
    int idx=start;
    while(idx<=end && preOrder[idx]<=root){
        idx++;
    }
    // preOrder[idx]>root. so our left subtree is [start+1, idx-1]. righ subtree is [idx, end]
    TreeNode<int>* leftTree= helper(preOrder, start+1, idx-1);
    TreeNode<int>* rightTree= helper(preOrder, idx, end);
    
    (*newNode).left=leftTree;  (*newNode).right=rightTree;
    return newNode;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    return helper(preOrder, 0, preOrder.size()-1);
}