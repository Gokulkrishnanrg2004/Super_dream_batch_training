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
    ListNode* reverse(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp!=nullptr)
        {
            ListNode* nextl = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextl;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head->next==nullptr && left==right)
            return head;
        
        ListNode* leftnode = head;
        ListNode* leftprev = nullptr;
        int count=1;
        while(count<left)
        {
            leftprev = leftnode;
            leftnode = leftnode->next;
            count++;
        }
        ListNode* rightnode = leftnode;
        ListNode* rightnext = rightnode;
        while(count<right)
        {
            rightnode = rightnode->next;
            count++;
        }
        rightnext = rightnode->next;

        //to separate as three separate linked lists
        if(leftprev)
            leftprev->next = nullptr;

        rightnode->next = nullptr;
        ListNode* newhead = reverse(leftnode);
        leftnode->next = rightnext;
        if(leftprev)
            leftprev->next = newhead;
        else 
            head = newhead;
        return head;
    }
};
