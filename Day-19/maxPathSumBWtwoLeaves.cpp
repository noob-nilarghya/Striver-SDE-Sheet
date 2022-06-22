long long int maxi=0;

long long int helper(TreeNode<int>* root){ // return maxSum possible from root to any node down below
    if(root==NULL){
        return 0;
    }
    long long int leftLongestPathSum= helper((*root).left);
    long long int rightLongestPathSum= helper((*root).right);
    
    maxi=max(maxi, leftLongestPathSum+(*root).val+rightLongestPathSum); // actual curved sum (stored in maxi)
    
    return (*root).val+max(leftLongestPathSum, rightLongestPathSum);
}

long long int findMaxSumPath(TreeNode<int> *root){
    if(root==NULL){ return -1; }
    if((*root).left==NULL || (*root).right==NULL){ return -1; }
    maxi=0;
    long long int a= helper(root);
    return maxi;
}