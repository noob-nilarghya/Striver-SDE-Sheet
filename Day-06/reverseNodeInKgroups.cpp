// Important Question
#include <bits/stdc++.h> 

Node* reverseLL(Node* head){
    if(head==NULL || (*head).next==NULL){ return head; }
    Node* temp=(*head).next;
    Node* reversedHead= reverseLL((*head).next);
    (*temp).next=head;
    (*head).next=NULL;
    return reversedHead;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(n>0 && b[0]==0){ // block size is 0
        return getListAfterReverseOperation(head, n-1, b+1);
    }
    if(n>0 && b[0]==1){ // block size is 1
        Node* temp=getListAfterReverseOperation((*head).next, n-1, b+1);
        (*head).next=temp;
        return head;
    }
	if(head==NULL || (*head).next==NULL || n==0){ return head; } 
    
    int block=b[0]; block--;
    Node* temp=head;
    while(temp!=NULL && block--){
        temp=(*temp).next;
    }
    if(temp==NULL){ // remaining element size is less than block size
        Node* reversedHead= reverseLL(head);
        return reversedHead;
    }
    // temp is at the last element of current block

    Node* nodeOnwards=(*temp).next;
    (*temp).next=NULL; // breaking 
    Node* reversedHead= reverseLL(head); // reversing the block
    Node* recursive= getListAfterReverseOperation(nodeOnwards,n-1,b+1);
    (*head).next=recursive;
    return reversedHead;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)