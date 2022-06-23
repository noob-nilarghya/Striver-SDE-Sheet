
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q) {
	if(root==NULL){
        return NULL;
    }
    if(root==P || root==Q){
        return root;
    }
    if((*P).data>(*root).data && (*Q).data>(*root).data){
        return LCAinaBST((*root).right, P, Q);
    }
    else if((*P).data<(*root).data && (*Q).data<(*root).data){
        return LCAinaBST((*root).left, P, Q);
    }
    return root;
}
