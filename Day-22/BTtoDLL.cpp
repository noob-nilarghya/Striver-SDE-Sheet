void inOrder(Node* root, vector<Node*>& vec){
    if(root==NULL){
        return;
    }
    inOrder((*root).left, vec);
    vec.push_back(root);
    inOrder((*root).right, vec);
    return;
}

Node* BTtoDLL(Node* root) {
    vector<Node*> vec;
    inOrder(root, vec); 
    int idx=0; Node* head;
    Node* prev=NULL;
    Node* curr=vec[idx];
    head=curr;
    
    (*curr).left=prev; idx++;
    
    while(idx != vec.size()){
        prev=curr;
        curr=vec[idx];
        (*prev).right=curr;
        (*curr).left=prev;
        idx++;
    }
    return head;
}
// Time Complexity: O(N)
// Space Complexity: O(N)+O(N)[auxilary]


//----------------------------------------------------------------------------



//Function to convert binary tree to doubly linked list and return it.
void inOrder(Node* root, Node*& head, Node*& tail){
    if(root==NULL){
        return;
    }
    inOrder((*root).left, head, tail);
    if(head==NULL){
        tail=root;
        head=root;
    }
    else{
        (*tail).right=root;
        (*root).left=tail; // we are changing connection in (*root).left
        // but it wont affect our traversal pattern as now we will go to (*root).right
        tail=(*tail).right;
    }
    inOrder((*root).right, head, tail);
    return;
}

Node* bToDLL(Node *root){
    
    Node* tail=NULL;
    Node* head=NULL;
    inOrder(root, head, tail);
    
    return head;
}
// Time Comolexity: O(N)
// Space Complexity: O(N)[auxilary]


/* In the question where we have to flatten BT in singly LL is different because there we have to 
flatten it in pre-order fashion, so we can't change (*root).left pinter (as soon after these we need to go to left child) */