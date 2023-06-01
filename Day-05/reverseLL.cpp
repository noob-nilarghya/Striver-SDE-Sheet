
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) {
    if(head==NULL || (*head).next==NULL){ return head; }
    
    // Iterative Way
    LinkedListNode<int>* curr=head; LinkedListNode<int>* prev=NULL; LinkedListNode<int>* after;
    while(curr!=NULL){
        after=(*curr).next;
        (*curr).next=prev;
        prev=curr; curr=after;
    }
    return prev;
    
    // Recursive Way
    LinkedListNode<int>* temp=(*head).next;
    LinkedListNode<int>* reversedHead= reverseLinkedList((*head).next);
    (*temp).next=head;
    (*head).next=NULL;
    return reversedHead;
}

// Time Complexity: O(N)
// Space Complexity: O(1)