#include <bits/stdc++.h> 

int len(LinkedListNode<int> *head){
    int cnt=0;
    LinkedListNode<int>* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=(*temp).next;
    }
    return cnt;
}

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k){
    int size=len(head);
    if(k<0 || k>size){ return head; } 
    if(k==0){ return head; }
    
    if(k==size){ // we need to remove head itself
        LinkedListNode<int>* newHead=(*head).next;
        (*head).next=NULL; delete(head);
        return newHead;
    }
    int iteration=size-k-1;
    LinkedListNode<int>* temp=head;
    while(iteration--){
        temp=(*temp).next;
    }
    LinkedListNode<int>* nodeToBeDel=(*temp).next;
    LinkedListNode<int>* delAfterNode=(*nodeToBeDel).next;
    (*temp).next=delAfterNode;
    (*nodeToBeDel).next=NULL; delete(nodeToBeDel);
    return head;
}

// Approach 2:

// Instaed of 2 traversal, we can make it by single traversal with the help of "2 POINTER TECHNIQUE"
// Put 1st pointers at the Kth NODE FROM START, put 2nd pointer at the HEAD.
// Now simultanously move both pointer UNTIL 1st pointer reaches end (pointing to last node (before NULL)), 
// at this point of time, 2nd pointer will be pointing at the required node itself (Kth node from end)!

// Time Complexity: O(N)
// Space Complexity: O(1)

