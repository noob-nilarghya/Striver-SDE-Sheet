//                                      [ VERY VERY IMPORTANT ]

#include <bits/stdc++.h>

void parentRegister(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>& m){
    queue<BinaryTreeNode<int>*> q;
    q.push(root); m[root]=NULL;
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front(); q.pop();
        if((*front).left != NULL){
            m[(*front).left]=front;
            q.push((*front).left);
        }
        if((*front).right != NULL){
            m[(*front).right]=front;
            q.push((*front).right);
        }
    }
    return;
}

BinaryTreeNode<int>* search(BinaryTreeNode<int>* root, int key){
    if(root==NULL){
        return NULL;
    }
    if((*root).data==key){ return root; }
    BinaryTreeNode<int>* leftTree= search((*root).left, key);
    if(leftTree != NULL){ return leftTree; }
    BinaryTreeNode<int>* rightTree= search((*root).right, key);
    if(rightTree != NULL){ return rightTree; }
    
    return NULL;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start){
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> m;
    parentRegister(root, m);
    BinaryTreeNode<int>* target=search(root, start);
    
    // Now I will do level order traversal with NULL (BFS) from TARGET, burn all adjecent nodes & update time
    int time=0;
    unordered_map<BinaryTreeNode<int>*, bool> isVisited;
    queue<BinaryTreeNode<int>*> q;
    q.push(target);  q.push(NULL); isVisited[target]=true;
    
    while(!q.empty()){
        BinaryTreeNode<int>* front=q.front(); q.pop();
        if(front != NULL){
            /* Now I can go in 3 dierections, -> to parent (if not burnt)
                                              -> to left child (if not burnt)
                                              -> to right child (if not burnt) */
                                              
            BinaryTreeNode<int>* par=m[front];
            if(par != NULL){ // parent
                if(isVisited.count(par)==0){
                    q.push(par);
                    isVisited[par]=true;
                }
                
            }
            if((*front).left != NULL){ // left
                if(isVisited.count((*front).left)==0){
                    q.push((*front).left);
                    isVisited[(*front).left]=true;
                }  
            }
            if((*front).right != NULL){ // right
                if(isVisited.count((*front).right)==0){
                    q.push((*front).right);
                    isVisited[(*front).right]=true;
                }
            }
        }
        else if(front == NULL){
            q.push(NULL);
            if(q.size()==1){
                break;
            }
            time++; 
        }
    }
    return time;
}

