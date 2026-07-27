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
        if (!head)
            return nullptr;
        
        Node* curr = head;

        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }

        curr = head;

        while (curr) {
            Node* copy = curr->next;

            if (curr->random) {
                copy->random = curr->random->next;
            } else {
                copy->random = nullptr;
            }
            
            curr = curr->next->next;
        }

        curr = head;
        Node* newHead = head->next;

        while (curr) {
            Node *copy = curr->next;
            curr->next = copy->next;
            if (curr->next) {
                copy->next = curr->next->next;
            }

            curr = curr->next;
        }

        return newHead;
    }
};
