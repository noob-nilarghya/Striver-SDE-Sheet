#include <bits/stdc++.h> 

LinkedListNode<int>* reverseLL(LinkedListNode<int>* head){
    if(head==NULL || (*head).next==NULL){  return head;  }
    LinkedListNode<int>* temp=(*head).next;
    LinkedListNode<int>* reversedHead= reverseLL((*head).next);
    (*temp).next=head;
    (*head).next=NULL;
    return reversedHead;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL || (*head).next==NULL){ return true; }
    LinkedListNode<int>* slow=head;
    LinkedListNode<int>* fast=(*head).next;
    while(fast!=NULL && (*fast).next!=NULL){
        slow=(*slow).next;
        fast=(*fast).next->next;
    }
    
    // Break original LL into 2 components
    LinkedListNode<int>* head2=(*slow).next;
    (*slow).next=NULL;
    LinkedListNode<int>* reversedHead= reverseLL(head2);
    
    while(head!=NULL && reversedHead!=NULL){
        if((*head).data != (*reversedHead).data){ return false; }
        head=(*head).next; reversedHead=(*reversedHead).next;
    }
    return true;
}