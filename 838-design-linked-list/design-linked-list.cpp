class Node 
{
  public:
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
    next = nullptr;
  }  
};
class MyLinkedList 
{
public:
    Node* head;
    int size;
    MyLinkedList() 
    {
        head = NULL;
        size=0;
    }
    // int size()
    // {
    //     int count=0;
    //     Node* temp = head;
    //     while(temp!=nullptr)
    //     {
    //         count++;
    //         temp = temp-next;
    //     }
    //     return count;
    // }
    int get(int index) 
    {
        if(head==NULL)
            return -1;
        if(index<0 || index>=size)
            return -1;
        Node* temp = head;
        int count=0;
        while(temp!=nullptr)
        {
            if(count==index)
            break;
            count++;
            temp=temp->next;
        }
        return temp->data;
        
    }
    
    void addAtHead(int val) 
    {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    void addAtTail(int val) 
    {
        Node* newNode = new Node(val);
        if(head==nullptr)
            head = newNode;
        else 
        {
            Node* temp = head;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) 
    {
         if(index>size || index<0)
            return;
        else if(index==0)
        {
            //  Node* newNode = new Node(val);
            // newNode->next = head;
            // head = newNode;
            // size++;
            addAtHead(val);
        }
        else 
        {
            Node* newNode = new Node(val);
            Node* temp = head;
            int count=1;
            while(count<index)
            {
                count++;
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) 
    {
        if(head==NULL)
            return;
        else if(index>=size || index<0)
            return;
        else if(index==0)
        {
            Node* temp = head;
            head = head->next;
            delete(temp);
        }
        else 
        {
            Node* temp = head;
            int count=1;
            while(count<index)
            {
                temp = temp->next;
                count++;
            }
            Node* nextl = temp->next;
            temp->next = nextl->next;
            delete(nextl);
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */