/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       if(!head) return nullptr;

       unordered_map<Node*,Node*>nodemap;
       Node* current = head;
       while(current)
       {
        nodemap[current] = new Node(current->val);
        current = current->next;
       }
       current = head;
       while(current)
       {
        nodemap[current]->next = nodemap[current->next];
        nodemap[current]->random = nodemap[current->random];
        current = current->next;
       }
       return nodemap[head];
    }
};