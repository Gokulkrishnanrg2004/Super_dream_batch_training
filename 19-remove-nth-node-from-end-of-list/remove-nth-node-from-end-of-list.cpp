class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }
        // Edge case if the input is
        // head = [1,2,3], n = 3 such that we need to remove 1 so that we return head->next
        if(fast==nullptr)
        {
            return head->next;
        }
        while(fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;


    }
};