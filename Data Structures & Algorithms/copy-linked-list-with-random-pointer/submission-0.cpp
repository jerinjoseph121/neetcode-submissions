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
        unordered_map<Node*, Node*> mpp;

        Node* ptr = head;
        Node* curr;

        while (ptr) {

            if (mpp.count(ptr)) {
                curr = mpp[ptr];
            } else {
                curr = new Node(ptr->val);
                mpp[ptr] = curr;
            }

            if (ptr->random) {
                if (mpp.count(ptr->random)) {
                    curr->random = mpp[ptr->random];
                } else {
                    curr->random = new Node(ptr->random->val);
                    mpp[ptr->random] = curr->random;
                }
            } else {
                curr->random = nullptr;
            }

            if (ptr->next) {
                if (mpp.count(ptr->next)) {
                    curr->next = mpp[ptr->next];
                } else {
                    curr->next = new Node(ptr->next->val);
                    mpp[ptr->next] = curr->next;
                }
            } else {
                curr->next = nullptr;
            }

            ptr = ptr->next;
        }

        return mpp[head];
    }
};
