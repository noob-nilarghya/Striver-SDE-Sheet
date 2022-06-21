#include <bits/stdc++.h>

int getMaxWidth(TreeNode<int> *root){
    if(root==NULL){ return 0; }
    // perform level order traversal with NULL between 2 levels
    
    queue<TreeNode<int>*> q; int maxWidth=INT_MIN; int cnt=0;
    q.push(root); q.push(NULL);
    
    while(!q.empty()){
        TreeNode<int>* front=q.front(); q.pop();
        
        if(front != NULL){
            cnt++;
            
            if((*front).left != NULL){ q.push((*front).left); }
            if((*front).right != NULL){ q.push((*front).right); }
        }
        else if(front == NULL){
            q.push(NULL);
            maxWidth=max(maxWidth, cnt);
            cnt=0;
            if(q.size()==1){ break; }
        }
    }
    return maxWidth;
}