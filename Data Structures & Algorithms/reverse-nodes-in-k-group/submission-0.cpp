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
    ListNode* reverse(ListNode* head, ListNode* end, ListNode* prevHead) {
        ListNode* ptr = head;
        ListNode* prevPtr = nullptr;

        while (ptr && ptr != end) {
            ListNode* temp = ptr->next;
            ptr->next = prevPtr;
            prevPtr = ptr;
            ptr = temp;
        }

        head->next = ptr;
        prevHead->next = prevPtr;

        return prevPtr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        ListNode* currHead = head;

        ListNode* resHead = new ListNode();
        ListNode* prevHead = resHead;

        int count = 0;
        
        while (ptr) {
            ptr = ptr->next;
            count++;

            if (count == k) {
                ListNode* updHead = reverse(currHead, ptr, prevHead);
                count = 0;
                prevHead = currHead;
                currHead = currHead->next;
            }
        }

        return resHead->next;
    }
};
