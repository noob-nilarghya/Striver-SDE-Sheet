//                    [ VERY VERY IMPORTANT ]

void helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    if((*root).left == NULL && (*root).right == NULL){ return; }
    int sum=0;
    if((*root).left!=NULL){ sum+=(*root).left->data; }
    if((*root).right != NULL){ sum+=(*root).right->data; }
    
    if(sum<=(*root).data){ // update child with (*root).data
        if((*root).left != NULL){ (*root).left->data= (*root).data;  }
        if((*root).right != NULL){ (*root).right->data= (*root).data; }  
    }
    else if(sum>(*root).data){ // update root with child sum
        (*root).data=sum;  
    }
    
    helper((*root).left);
    helper((*root).right);
    
    sum=0;
    if((*root).left!=NULL){ sum+=(*root).left->data; }
    if((*root).right != NULL){ sum+=(*root).right->data; }

    if(sum > (*root).data){  // update root with child sum
        (*root).data=sum;
    }
    return;  
}

void changeTree(BinaryTreeNode<int>* root) {
    helper(root);
}  

