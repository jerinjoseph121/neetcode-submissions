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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;

        ListNode* head = new ListNode();

        ListNode* prevPtr = head;



        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1->val <= ptr2->val) {
                prevPtr->next = ptr1;
                ptr1 = ptr1->next;
            } else {
                prevPtr->next = ptr2;
                ptr2 = ptr2->next;
            }

            prevPtr = prevPtr->next;
        }

        if (ptr1 != nullptr) {
            prevPtr->next = ptr1;
        } else if (ptr2 != nullptr) {
            prevPtr->next = ptr2;
        }

        return head->next;
    }
};
