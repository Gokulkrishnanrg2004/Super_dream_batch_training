/*
Sample input 1 : 1 2 3
                     1
Sample output 1 : 1 2 4
*/

class Solution {
  public:
    Node* reverse(Node* head)
    {
        Node* temp = head;
        Node* prev = nullptr;
        while(temp!=nullptr)
        {
            Node* nextl = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextl;
        }
        return prev;
    }
    Node* addOne(Node* head) 
    {
        if(head==nullptr)
            return head;
        Node* newHead = reverse(head);
        int carry = 1;
        Node* temp = newHead;
        Node* prev = nullptr;
        while(temp!=nullptr)
        {
            temp->data = temp->data + carry;
            if(temp->data<=9)
            {
                carry = 0;
                break;
            }
            else 
            {
                temp->data = 0;
            }
            // prev = temp;
            temp = temp->next;
        }
        // Edge case for input such as 999
       newHead= reverse(newHead);
        if(carry==1)
        {
            Node* newNode = new Node(carry);
            // prev->next = newNode;
            newNode->next=newHead;
            newHead=newNode;
        }
        return newHead;
    }
};
