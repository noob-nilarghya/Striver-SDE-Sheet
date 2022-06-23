
bool helper(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1==NULL && root2==NULL){ return true; }
    if(root1==NULL && root2!=NULL){ return false; }
    if(root1!=NULL && root2==NULL){ return false; }
    
    bool a=helper((*root1).left, (*root2).right); // root1 suffers INORDER, root2 suffers REVERSE INORDER
    if(a==false){ return false; }
    
    if((*root1).data != (*root2).data){  return false;   } // compare root1 data & root2 data
    
    bool b=helper((*root1).right, (*root2).left); // root1 suffers INORDER, root2 suffers REVERSE INORDER
    if(b==false){ return false; }
    
    return true;
}

bool isSymmetric(BinaryTreeNode<int>* root){
    if(root==NULL){ return true; }
    return helper((*root).left, (*root).right);
}