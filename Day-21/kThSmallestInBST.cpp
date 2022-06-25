int cnt=0; int ans=-1;
void helper(TreeNode<int>* root, int k){ // normal InOrder
    if(root==NULL){
        return;
    }
    helper((*root).left, k);
    cnt++;
    if(cnt==k){
        ans=(*root).data;
        return;
    }
    helper((*root).right, k);
}

int kthSmallest(TreeNode<int>* root, int k){
    cnt=0; ans=-1;
	helper(root, k);
    return ans;
}