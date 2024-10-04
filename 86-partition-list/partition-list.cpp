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
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* dummyNode1 = new ListNode(-1);
        ListNode* dummyNode2 = new ListNode(-1);
        ListNode* current1 = dummyNode1;
        ListNode* current2 = dummyNode2;
        ListNode* temp = head;
        while(temp!=nullptr)
        {
            if(temp->val<x)
            {
                current1->next = temp;
                temp = temp->next;
                current1 = current1->next;
            }
            else if(temp->val>=x)
            {
                current2->next = temp;
                temp = temp->next;
                current2 = current2->next;
            }
        }
        current1->next = dummyNode2->next;
        current2->next = nullptr;
        return dummyNode1->next;
    }
};