bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){ return false; }
    if((*root).data==x){ return true; }
    
    if((*root).data > x){ // go to left
        return searchInBST((*root).left, x);
    }
    return searchInBST((*root).right, x);
}