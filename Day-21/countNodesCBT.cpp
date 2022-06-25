//                    Taken from LeetCode [ IMP ]
class Solution {
public:
    int helperLeft(TreeNode* root){ // O(logN)
        TreeNode* temp=root; int cnt=0;
        while(temp != NULL){
            cnt++;
            temp=(*temp).left;
        }
        return cnt;
    }
    
    int helperRight(TreeNode* root){ // O(logN)
        TreeNode* temp=root; int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=(*temp).right;
        }
        return cnt;
    }
    
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if((*root).left==NULL && (*root).right==NULL){
            return 1;
        }
        
        int leftHeight=helperLeft((*root).left);
        int rightHeight=helperRight((*root).right);
        
        if(leftHeight == rightHeight){ // full binary tree (even the last level is also filled)
            return (int)(pow(2, leftHeight+1)+0.5)-1;
        }
        
        // This will again cost me O(logN)
        
        int leftCountNode= countNodes((*root).left);
        int rightCountNode= countNodes((*root).right);
        return 1+leftCountNode+rightCountNode;
    }
    
    // Time Complexity: O( (logN)^2 )
};