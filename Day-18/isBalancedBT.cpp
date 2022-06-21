pair<int,bool> helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int, bool> p;
        p.first=0; p.second=true;
        return p;
    }
    
    pair<int, bool> leftPair= helper((*root).left);
    pair<int, bool> rightPair= helper((*root).right);
    
    pair<int, bool> finalPair;
    finalPair.first=1+max(leftPair.first, rightPair.first);
    
    if(abs(leftPair.first-rightPair.first)<=1 && leftPair.second && rightPair.second){
        finalPair.second=true;
    }
    else{ finalPair.second= false; }
    return finalPair;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    pair<int, bool> p= helper(root);
    return p.second;
}