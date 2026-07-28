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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (auto &node: lists) {
            if (node) {
                pq.push({node->val, node});
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top().second;
            pq.pop();

            ListNode* newNode = new ListNode(curr->val);
            ptr->next = newNode;
            ptr = ptr->next;

            curr = curr->next;
            if (curr) {
                pq.push({curr->val, curr});
            }
        }

        return dummy->next;
    }
};
