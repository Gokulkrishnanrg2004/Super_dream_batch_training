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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        int count=1;
        while(count<k)
        {
            fast = fast->next;
            count++;
        }
        ListNode* prev = fast;    
        while(fast->next!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        swap(slow->val,prev->val);
        return head;
    }
};