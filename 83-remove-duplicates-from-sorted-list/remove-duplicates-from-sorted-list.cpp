class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
            return head;
        ListNode* temp = head;
        while(temp!=nullptr && temp->next!=nullptr)
        {
            if(temp->val == temp->next->val)
            {
                ListNode* del = temp->next;
                temp->next = del->next;
                delete(del);
            }
            else 
            {
                temp = temp->next;
            }
        }
        return head;
    }
};