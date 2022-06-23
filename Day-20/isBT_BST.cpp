class util{
    public:
    int mini;
    int maxi;
    bool isBST;
};

util helper(BinaryTreeNode<int> *root){
    util t;
    if(root==NULL){
        t.mini=INT_MAX;
        t.maxi=INT_MIN;
        t.isBST=true;
        return t;
    }
    
    util leftTree= helper((*root).left);
    util rightTree= helper((*root).right);
    
    util finalObj;
    finalObj.mini= min((*root).data, min(leftTree.mini, rightTree.mini));
    finalObj.maxi= max((*root).data, max(leftTree.maxi, rightTree.maxi));
    
    if((*root).data >= leftTree.maxi && (*root).data <= rightTree.mini && leftTree.isBST && rightTree.isBST){
        finalObj.isBST=true;
    }
    else{ finalObj.isBST=false; }
    
    return finalObj;
}

bool validateBST(BinaryTreeNode<int> *root) {
    util finalObj= helper(root);
    return finalObj.isBST;
}