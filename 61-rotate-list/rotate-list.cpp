/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head; // If the list is empty, has only one node, or no rotation needed
        }

        // Step 1: Find the length of the list
        int length = 1; // Start with 1 as we traverse from head
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 2: Calculate the effective rotations needed
        k = k % length; // If k > length, use k modulo length
        if (k == 0) {
            return head; // No change needed if k is a multiple of length
        }

        // Step 3: Make the list circular by connecting the last node to the head
        tail->next = head;

        // Step 4: Find the new tail (length - k steps from the head)
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) { // Traverse to the new tail
            newTail = newTail->next;
        }

        // Step 5: Set the new head and break the circular connection
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;    
    }
};