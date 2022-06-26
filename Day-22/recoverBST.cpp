
//  Recover Binary Search Tree - Striver  [ VERY VERY IMPORTANT ]

class Solution {
public:
	TreeNode* curr=NULL;  TreeNode* pre=NULL; TreeNode* firstMistake=NULL; TreeNode* firstMistakeNxt=NULL; TreeNode* secondMistake=NULL;
    
    void inOrder(TreeNode* root) {
		if(root==NULL){
            return;
        }
        inOrder((*root).left);
        curr=root;
        
        if(pre!=NULL && (*pre).val>(*curr).val){
            if(firstMistake==NULL){ // first Mistake
                firstMistake=pre;
                firstMistakeNxt=curr;
            }
            else{ // second Mistake
                secondMistake=curr;
            }
        }
        pre=curr;
        
        inOrder((*root).right);
	}
    
	void recoverTree(TreeNode* root) {
        inOrder(root);
        
	    if(secondMistake==NULL){ // nodes are adjecent
            int temp=(*firstMistake).val;
            (*firstMistake).val=(*firstMistakeNxt).val;
            (*firstMistakeNxt).val=temp;
            return;
        }
        else{ // root are not adjecent
            int temp=(*firstMistake).val;
            (*firstMistake).val=(*secondMistake).val;
            (*secondMistake).val=temp;
            return;
        }
	}
};