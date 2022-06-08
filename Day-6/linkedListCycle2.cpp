#include <bits/stdc++.h> 
// Floyd's Hare and Tortoise Algorithm

Node *firstNode(Node *head){
    if(head==NULL){ return NULL; }
    
    // Step 1: Detect wheather there is cycle or not
	Node* slow=head; Node* fast=head;
    while(fast!=NULL && (*fast).next!=NULL){ // Take care of condition when there is no cycle in LL
        // move slow by 1X, fast by 2X
        slow=(*slow).next;
        fast=(*fast).next->next;
        if(slow==fast){ break; } // stop when slow==fast [indicates, cycle has been detected]
    }
    if(fast==NULL || (*fast).next==NULL){ return NULL; } // no cycle detected
    
    // Step2: If cycle dtected, find where the cycle starts
    // Now bring slow to head & move slow & fast by 1X both until slow==fast
    slow=head;
    while(slow!=fast){
        slow=(*slow).next;
        fast=(*fast).next;
    }
    return slow;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// This algorithm is also used to "Find Duplicates in Array of Unique Elements"