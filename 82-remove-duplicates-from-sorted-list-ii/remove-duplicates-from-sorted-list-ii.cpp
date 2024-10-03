class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
            return head;
        
        ListNode* dummyNode = new ListNode(-1);
        ListNode* current = dummyNode;
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp!=nullptr)
        {
            if(temp->next && temp->val == temp->next->val)
            {
                while(temp->next && temp->val == temp->next->val)
                {
                    temp = temp->next;
                }
                temp = temp->next;
            }
            else 
            {
                current->next = temp;
                current = current->next;
                temp = temp->next;
            }
        }
        current->next = nullptr;

        return dummyNode->next;
    }
};
