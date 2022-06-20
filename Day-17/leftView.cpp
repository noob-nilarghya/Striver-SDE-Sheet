#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getLeftView(TreeNode<int> *root){
    //   Perform normal level order traversal. 
    //   Whenever NULL encountered in front (which is popped) --> vec.pb(q.front)

    queue<TreeNode<int>*> q; vector<int> ans;
    if(root==NULL){ return ans; }
    q.push(root); q.push(NULL);  ans.push_back((*root).data);
    
    while(!q.empty()){
        TreeNode<int>* front=q.front(); q.pop();
        if(front !=NULL){
            TreeNode<int>* left=(*front).left; TreeNode<int>* right=(*front).right;
            if(left !=NULL){  q.push(left);  }
            if(right != NULL){ q.push(right); }
        }
        else if(front == NULL){
            q.push(NULL);
            if(q.size()==1){
                break;
            }
            TreeNode<int>* temp=q.front(); // just push q.front in ans vector
            ans.push_back((*temp).data);
        }
    }
    return ans;
}

