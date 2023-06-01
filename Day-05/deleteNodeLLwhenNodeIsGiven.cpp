#include <bits/stdc++.h> 

// In a linked List (whose head is not given), a refference to node is given which we need to delete.
// For delteing node at (i), we need our pointer to be at (i-1). But here we can't delete node (as our pointer itself is at node).
//  Here we can delete "(*node).next", but can't delete "node".
// As the values are unique, we interchange values of (node) <---> ((*node).next). And delete "(*node).next".

void deleteNode(LinkedListNode<int>* node) {
    // as node to be deleted is guaranteed to be not a tail node, we can safely access (*node).next
    int temp=(*node).next->data;
    (*node).data=temp;
    // now delete (*node).next

    LinkedListNode<int>* nodeNxt=(*node).next;
    LinkedListNode<int>* nodeNxtNxt=(*nodeNxt).next;
    (*node).next=nodeNxtNxt;
    (*nodeNxt).next=NULL; delete(nodeNxt);
    return;
}

// Time Complexity: O(1)
// Space Complexity: O(1)