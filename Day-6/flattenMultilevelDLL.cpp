// Problem from : LeetCode [IMP]

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    pair<Node*, Node*> helper(Node* head){
        
        Node* temp=head; Node* tail;
        while(temp!=NULL){
            
            if((*temp).child!=NULL){
                
                if(temp->next != NULL){
                    Node* tempNxt= (*temp).next;
                    pair<Node*, Node*> p= helper((*temp).child);
                    (*temp).child=NULL;
                    (*temp).next= p.first; (*(p.first)).prev=temp;
                    (*(p.second)).next=tempNxt; (*tempNxt).prev=p.second;
                }
                
                if(temp->next==NULL){ // last node has child
                    pair<Node*, Node*> p= helper((*temp).child);
                    (*temp).child=NULL;
                    (*temp).next= p.first; (*(p.first)).prev=temp;
                    tail=p.second;
                }
            }
            else if((*temp).child==NULL && (*temp).next==NULL){ tail=temp; }
            
            temp=(*temp).next;
        }
        return {head, tail};
    }
    
    Node* flatten(Node* head) {
        pair<Node*, Node*> p=helper(head);
        return p.first;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)