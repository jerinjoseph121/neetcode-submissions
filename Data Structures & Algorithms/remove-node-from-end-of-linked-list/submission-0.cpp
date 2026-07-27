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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;

        ListNode* ptr = head;

        while(ptr) {
            size++;
            ptr = ptr->next;
        }

        int nodeToRemove = size - n + 1;

        if (nodeToRemove == 1) {
            return head->next;
        }

        ptr = head;
        ListNode* prevPtr = nullptr;
        int count = 0;

        while (ptr) {
            count++;

            if (count == nodeToRemove) {
                prevPtr->next = ptr->next;
                ptr->next = nullptr;
                break;
            }

            prevPtr = ptr;
            ptr = ptr->next;
        }

        return head;
    }
};
