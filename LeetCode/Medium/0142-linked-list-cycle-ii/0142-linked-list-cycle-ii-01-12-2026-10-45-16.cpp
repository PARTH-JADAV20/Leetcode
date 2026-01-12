/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;

        while (curr != nullptr) {
            if (visited.count(curr)) {
                return curr;   // cycle entry
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return nullptr;  // no cycle
    }
};
