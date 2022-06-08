#include <bits/stdc++.h> 
// Just move slow and fast pointer. (i.e perform only step1 of "Hare & Tortoise Algotithm")

bool detectCycle(Node *head){
	Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && (*fast).next!=NULL){
        slow=(*slow).next;
        fast=(*fast).next->next;
        if(slow==fast){ return true; }
    }
    return false;
}