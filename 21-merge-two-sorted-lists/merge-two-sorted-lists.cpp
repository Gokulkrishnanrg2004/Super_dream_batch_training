// class Solution {
// public:
// 	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
//     {
//         if(l1==NULL)
//         {
//             return l2;
//         }	
//         if(l2==NULL)
//         {
//             return l1;
//         }
//         if(l1->val <= l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next,l2);
//             return l1;
//         }
//         else 
//         {
//             l2->next = mergeTwoLists(l1,l2->next);
//             return l2;
//         }
// 	}
// };	
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
};	