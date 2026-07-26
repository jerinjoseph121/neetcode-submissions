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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* prevPtr = nullptr;

        while (fast) {
            prevPtr = slow;
            slow = slow->next;

            if (fast->next)
                fast = fast->next->next;
            else
                break;
        }

        ListNode* ptr = slow;
        prevPtr->next = nullptr;
        prevPtr = nullptr;

        while (ptr) {
            ListNode* temp = ptr->next;
            ptr->next = prevPtr;
            prevPtr = ptr;
            ptr = temp;
        }

        // ListNode* l = head;
        // ListNode* r = prevPtr;

        // cout<<"Left: "<<endl;

        // while (l) {
        //     cout<<l->val<<" ";
        //     l = l->next;
        // }
        // cout<<endl;

        // cout<<"Right:"<<endl;

        // while(r) {
        //     cout<<r->val<<" ";
        //     r = r->next;
        // }
        // cout<<endl;

        ListNode* lPtr = head;
        ListNode* rPtr = prevPtr;

        while (lPtr && rPtr) {
            ListNode* lTemp = lPtr->next;
            ListNode* rTemp = rPtr->next;
            lPtr->next = rPtr;
            rPtr->next = lTemp;
            lPtr = lTemp;
            rPtr = rTemp;
        }

        return;
    }
};
