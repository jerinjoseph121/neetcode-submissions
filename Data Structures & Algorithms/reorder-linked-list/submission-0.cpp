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
        vector<ListNode*> listArr;

        ListNode* ptr = head;

        while (ptr) {
            listArr.push_back(ptr);
            ptr = ptr->next;
        }

        int n = listArr.size();

        int low = 0;
        int high = n - 1;

        ListNode *lPtr, *rPtr;

        while (low < high) {
            lPtr = listArr[low];
            rPtr = listArr[high];

            if (low + 1 < high) {
                rPtr->next = lPtr->next;
            } else {
                rPtr->next = nullptr;
            }

            lPtr->next = rPtr;

            low++;
            high--;
        }

        listArr[low]->next = nullptr;

        return;
    }
};
