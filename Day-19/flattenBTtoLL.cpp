//                  [ VERY VERY IMPORTANT ]
// by morris pre-order traversal (in place constant space algorithm)

TreeNode<int> *flattenBinaryTree(TreeNode<int>* root) {
    TreeNode<int>* curr= root;
    while(curr != NULL){
        if(curr->left == NULL){
            // move to your right
            curr=(*curr).right;
        }
        else if(curr->left != NULL){
            TreeNode<int>* prev=(*curr).left;
            // prev is pointing to root of left sub-tree. Go to its extereme right
            while(prev->right != NULL){
                prev=(*prev).right;
            }
            // Now prev->right==NULL;
            prev->right= curr->right;
            curr->right=curr->left;

            (*curr).left=NULL;
            
            // now move to your right
            curr=(*curr).right; 
        }
    }
    return root;
}

// Time Complexity: O(N)
// Space Complexity: O(1)