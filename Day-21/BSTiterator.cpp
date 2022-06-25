// Approach 1: Space Complexity: O(N)
class BSTiterator{
    public:
    TreeNode<int>* root;
    stack<int> s;
    
    void helper(TreeNode<int>* root, stack<int>& s){ // reverse inOrder
        if(root==NULL){
            return;
        }
        helper((*root).right, s);
        s.push((*root).data);
        helper((*root).left, s);
        return;
    }
    
    BSTiterator(TreeNode<int> *root){
        this->root=root;
        helper(this->root, s);
    }
    
    int next(){
        if(hasNext()==false){
            return -1;
        }
        int temp=s.top(); s.pop();
        return temp;
    }

    bool hasNext(){
        return !s.empty();
    }
};

//---------------------------------------------------------------------------------------

// Approch 2: Space Complexity: O(H) ~H is height of BST

#include <bits/stdc++.h>
// Basically we need to do inOrder: Left Node Right

class BSTiterator{
    public:
    TreeNode<int>* root;
    stack<TreeNode<int>*> s;
    
    BSTiterator(TreeNode<int>* root){
        this->root=root;
        TreeNode<int>* temp=root;
        // stack store all left of root. Extreme left(smallest) will be at top
        while(temp != NULL){ // go till extreme left
            s.push(temp);
            temp=(*temp).left;
        }
    }

    int next(){
        TreeNode<int>* temp=s.top(); // extreme left(smallest).This root has no left so print it & move to its right
        s.pop();
        TreeNode<int>* newTemp=(*temp).right; // assume this as new Node (node of right subtree)
        
        // Now repeat the process by again going till its extreme left and so on..
        while(newTemp!=NULL){
            s.push(newTemp);
            newTemp=(*newTemp).left;
        }
        // again left most node of newTemp would be on stack top (which is technically inOrder successor of temp)
        int d=(*temp).data;
        return d;
    }

    bool hasNext(){
        return !s.empty();
    }
};
