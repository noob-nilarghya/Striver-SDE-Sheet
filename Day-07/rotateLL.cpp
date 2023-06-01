#include <bits/stdc++.h> 

int len(Node* head){
    Node* temp=head; int cnt=0;
    while(temp!=NULL){
        temp=(*temp).next;   cnt++;
    }
    return cnt;
}

Node *rotate(Node *head, int k) {
    if(k % len(head) == 0){ return head; }
    if(k>len(head)){  k= k%len(head); }
    
    Node* ptr1=head; Node* ptr2=head;
    while(k--){
        ptr1=(*ptr1).next;
    }
    while(ptr1->next!=NULL){
        ptr1=(*ptr1).next;
        ptr2=(*ptr2).next;
    }
    // Now my ptr2 is at newTail
    Node* newHead=(*ptr2).next;
    (*ptr2).next=NULL;
    (*ptr1).next=head;
    return newHead;
}

// Time Complexity: O(N)
// Space Complexity: O(1)