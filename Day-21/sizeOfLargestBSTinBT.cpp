class util{
    public:
    int maxi;
    int mini;
    bool isBST;
    int sizeBST;
};

util helper(TreeNode<int>* root){
    util finalUtil;
    if(root==NULL){
        finalUtil.maxi=INT_MIN;
        finalUtil.mini=INT_MAX;
        finalUtil.isBST=true;
        finalUtil.sizeBST=0;
        return finalUtil;
    }
    
    util leftTree= helper((*root).left);
    util rightTree= helper((*root).right);
    
    finalUtil.maxi=max((*root).data, max(leftTree.maxi, rightTree.maxi));
    finalUtil.mini=min((*root).data, min(leftTree.mini, rightTree.mini));
    
    if((*root).data >= leftTree.maxi && (*root).data <= rightTree.mini && leftTree.isBST && rightTree.isBST){
        finalUtil.isBST=true;
        finalUtil.sizeBST=leftTree.sizeBST+rightTree.sizeBST+1; // Imp step
    }
    else{
        finalUtil.isBST=false;
        finalUtil.sizeBST=max(leftTree.sizeBST, rightTree.sizeBST); // Imp step
    }
    return finalUtil;
}

int largestBST(TreeNode<int>* root) {
    util u=helper(root);
    return u.sizeBST;
}
