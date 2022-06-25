BinaryTreeNode<int>* ceilNode=NULL;
void helper(BinaryTreeNode<int>* root, int x){
    if(root==NULL){
        return;
    }
    if((*root).data==x){
        ceilNode=root;
        return;
    }
    else if((*root).data < x){ // go to right to find floor
        helper((*root).right, x);
    }
    else if((*root).data > x){ // this can be one of our element
        ceilNode=root;
        // achieve a ceil as closest to root as you can
        helper((*root).left, x);
    }
}

int findCeil(BinaryTreeNode<int>* root, int X){
    ceilNode=NULL;
    helper(root, X);
    if(ceilNode==NULL){  return -1;  } // all ele in tree is greater than X
    return (*ceilNode).data;
}
