#include <bits/stdc++.h>

vector<int> zigZagTraversal(BinaryTreeNode<int>* root){
    if(root==NULL){ vector<int> ans; return ans; }
    // perform normal level order traversal (with NULL) along with slight modification
   
    queue<BinaryTreeNode<int>*> q;
    stack<int> stk;
    int level=1; vector<int> ans;
    
    q.push(root); q.push(NULL);
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front(); q.pop();
        if(front != NULL){
            if(level%2 == 1){ // odd level
                ans.push_back((*front).data);
            }
            else if(level%2 == 0){ // even level
                stk.push((*front).data);
            }
            
            if((*front).left != NULL){
                q.push((*front).left);
            }
            if((*front).right != NULL){
                q.push((*front).right);
            }
        }
        else if(front == NULL){
            q.push(NULL);
            if(level%2 ==0){
                while(!stk.empty()){
                    ans.push_back(stk.top());
                    stk.pop();
                }
            }
            level++;
            if(q.size()==1){ break; }
        }
    }
    return ans;
}
