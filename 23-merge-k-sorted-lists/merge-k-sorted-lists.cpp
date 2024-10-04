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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1!=nullptr && temp2!=nullptr)
        {
            if(temp1->val >= temp2->val)
            {
                current->next = temp2;
                temp2 = temp2->next;
                current = current->next;
            }
            else 
            {
                current->next = temp1;
                temp1 = temp1->next;
                current = current->next;
            }
        }
        if(temp1!=nullptr)
        {
            current->next = temp1;
        }
        else if(temp2!=nullptr)
        {
            current->next = temp2;
        }
        return dummyNode->next;
	}
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
       if(lists.size()==0)
        return nullptr;
        ListNode* head = lists[0];
       for(int i=1;i<lists.size();i++)
       {
         head = mergeTwoLists(head,lists[i]);
       } 
       return head;
    }
};