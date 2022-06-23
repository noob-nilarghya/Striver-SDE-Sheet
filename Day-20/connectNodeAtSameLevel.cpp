#include <bits/stdc++.h>

void connectNodes(BinaryTreeNode<int>* root) {
    if(root==NULL){ return; }
    
    // we have to connect all nodes at the same level, so LEVER ORDER TRAVERSAL (with NULL)
    queue<BinaryTreeNode<int>*> q;
    q.push(root);   q.push(NULL);
    BinaryTreeNode<int>* head=NULL; BinaryTreeNode<int>* tail=NULL;
    
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front(); q.pop();
        
        if(front != NULL){
            if(head==NULL){ // first insertion
                head=front; tail=front;
            }
            else{
                (*tail).next=front;
                tail=(*tail).next;
            }
            
            if((*front).left != NULL){ q.push((*front).left); }
            if((*front).right != NULL){ q.push((*front).right); }
        }
        else if(front==NULL){
            q.push(NULL);
            head=NULL; tail=NULL;
            
            if(q.size()==1){ break; }
        }
    }
}