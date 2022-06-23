// Every problem in BST can be compared with BS problem in sorted array.
// Like this question is similar to finding ceil & floor of an element

BinaryTreeNode<int>* succ=NULL; // node just greater than key
void modBSSucc(BinaryTreeNode<int>* root, int key){
    if(root==NULL){ return; }
    if((*root).data==key){ // go to right of it
        modBSSucc((*root).right, key);
    }
    else if((*root).data > key){ // this can be one of my successor
        if(succ==NULL){ succ=root; }
        else{
            int d1=(*succ).data; int d2=(*root).data;
            if(d2<d1){ succ=root; }
        }
        // go to as close to key as possible
        modBSSucc((*root).left, key);
    }
    modBSSucc((*root).right, key);
}

BinaryTreeNode<int>* pre=NULL; // node just smaller than key
void modBSPre(BinaryTreeNode<int>* root, int key){
    if(root==NULL){ return; }
    if((*root).data==key){ // go to left of it
        modBSPre((*root).left, key);
    }
    else if((*root).data < key){ // this can be one of my predeccessor
        if(pre==NULL){ pre=root; }
        else{
            int d1=(*pre).data;  int d2=(*root).data;
            if(d1<d2){ pre=root; }
        }
        modBSPre((*root).right, key);
    }
    modBSPre((*root).left, key);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key){
    succ=NULL; pre=NULL;
    pair<int, int> p={-1, -1};
    if(root==NULL){ return p; }
    
    modBSSucc(root, key);
    modBSPre(root, key);
    
    if(pre != NULL){ p.first=(*pre).data; }
    if(succ != NULL){ p.second=(*succ).data; }
    return p;
}
