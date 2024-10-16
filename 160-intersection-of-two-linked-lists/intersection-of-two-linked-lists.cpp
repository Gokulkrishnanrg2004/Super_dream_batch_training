/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode* temp = headA;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }    
        temp->next = headA;
        
        // Cycle detection
        ListNode* slow = headB;
        ListNode* fast = headB;
        
        while(fast!=nullptr && fast->next!=nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast)
            {
                slow = headB;
                while(slow!=fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                temp->next = nullptr;
                return slow;
            }
        }
        temp->next = nullptr;
        return nullptr;
    }
};