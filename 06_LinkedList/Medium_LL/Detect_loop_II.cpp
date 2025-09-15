#include <iostream>
using namespace std;

Node* firstNode(Node* head) 
{
    
    // Initialize a slow and fast 
    // pointers to the head of the list
    Node* slow = head;  
    Node* fast = head;  

    // Phase 1: Detect the loop
    while (fast != NULL && fast->next != NULL) 
    {
        
        // Move slow one step
        slow = slow->next;        
        
        // Move fast two steps
        fast = fast->next->next;  

        // If slow and fast meet,
        // a loop is detected
        if (slow == fast) 
        {
            
             // Reset the slow pointer
             // to the head of the list
            slow = head; 

            // Phase 2: Find the first node of the loop
            while (slow != fast) 
            {
                
                // Move slow and fast one step
                // at a time
                slow = slow->next;  
                fast = fast->next;  

                // When slow and fast meet again,
                // it's the first node of the loop
            }
            
            // Return the first node of the loop
            return slow;  
        }
    }
    
     // If no loop is found, return NULL
    return NULL; 
}

/*
1.Phase 1 (Cycle detection):
    Use slow (1 step) and fast (2 steps).
    If they meet → loop exists.

2.Phase 2 (Find entry point):
    Reset slow to head.
    Move both slow and fast one step at a time.
    The node where they meet is the first node of the loop.
*/