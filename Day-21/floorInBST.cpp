TreeNode<int>* floor=NULL;
void helper(TreeNode<int>* root, int x){
    if(root==NULL){
        return;
    }
    if((*root).val==x){
        floor=root;
        return;
    }
    else if((*root).val < x){ // this can be one of our element
        floor=root;
        // achieve a floor as closest to root as you can
        helper((*root).right, x);
    }
    else if((*root).val > x){ // go to left to find floor
        helper((*root).left, x);
    }
}

int floorInBST(TreeNode<int>* root, int X){
    floor=NULL;
    helper(root, X);
    if(floor==NULL){  return -1;  } // all ele in tree is greater than X
    return (*floor).val;
}