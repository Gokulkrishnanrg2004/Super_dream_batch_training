class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (!head || !head->next)
            return head;
        
        // Create a dummy node to make edge cases easier to handle
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        ListNode* temp = head;

        while (temp) {
            // Check if the current node is a start of a duplicate sequence
            if (temp->next && temp->val == temp->next->val) {
                // Skip all nodes with the same value
                while (temp->next && temp->val == temp->next->val) {
                    temp = temp->next;
                }
                // Move temp one step further to skip the last duplicate
                temp = temp->next;
            } else {
                // Link the distinct node to the new list
                current->next = temp;
                current = current->next;
                temp = temp->next;
            }
        }

        // Ensure the last node points to nullptr to avoid cycles
        current->next = nullptr;

        return dummyNode->next;
    }
};
