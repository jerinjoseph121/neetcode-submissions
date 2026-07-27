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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        ListNode* newDummy = new ListNode();
        ListNode* ptr3 = newDummy;

        int carry = 0;

        while (ptr1 && ptr2) {
            int a = ptr1->val;
            int b = ptr2->val;

            int c = a + b + carry;

            int newDigit = c % 10;
            carry = c / 10;

            ptr3->next = new ListNode(newDigit);

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }

        while (ptr1) {
            int a = ptr1->val;
            int c = a + carry;

            int newDigit = c % 10;
            carry = c / 10;

            ptr3->next = new ListNode(newDigit);

            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }

        while (ptr2) {
            int b = ptr2->val;
            int c = b + carry;

            int newDigit = c % 10;
            carry = c / 10;

            ptr3->next = new ListNode(newDigit);

            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }

        if (carry) {
            ptr3->next = new ListNode(carry);
        }

        return newDummy->next;
    }
};
