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
    void deleteNode(ListNode* node) 
    {
        ListNode* temp = node;
        ListNode* prev = nullptr;
        while(temp!=nullptr && temp->next!=nullptr)
        {
            temp->val = temp->next->val;
            if(temp!=nullptr)
            {
                prev = temp;
                temp = temp->next;
            }
        }
        prev->next = nullptr;
        delete(temp);
    }
};
/*
    void deleteNode(ListNode* node)
    {
        node->next = node->next->val;
        node->next = node->next->next;
    }
*/