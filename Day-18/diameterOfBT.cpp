pair<int, int> helper(TreeNode<int>* root){
    //  BASE CASE
    if(root==NULL){
        pair<int, int> p;
        p.first=0;
        p.second=0;
        return p;
    }
    
    pair<int, int> left=helper((*root).left);
    pair<int, int> right=helper((*root).right);
    
    pair<int, int> finalPair;
    int height= 1+max(left.first, right.first);
    int dia= max(left.first+right.first, max(left.second, right.second));
    finalPair.first=height;  finalPair.second=dia;
    return finalPair;
}

int diameterOfBinaryTree(TreeNode<int>* root){
	pair<int, int> p=helper(root);
    return p.second;
}
