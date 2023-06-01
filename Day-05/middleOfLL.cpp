#include <bits/stdc++.h> 

Node *findMiddle(Node *head) {
    if(head==NULL || (*head).next==NULL){ return head; }
    Node* slow=head; Node* fast=head;
    while(fast!=NULL && (*fast).next!=NULL){
        slow=(*slow).next;
        fast=fast->next->next;
    }
    return slow;
}

// Time Complexity: O(N)
// Space Complexity: O(1)