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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* temp = head;
        
        if(head->next->next==nullptr){
            head->next = nullptr;
            return head;
        }

        int size = 1;
        while(temp->next!=nullptr){
            size++;
            temp = temp->next;
        }
        
        int indextodel = size/2;
        int count = 0;
        temp = head;
        for (int i = 0; i < indextodel ; i++) {
            temp = temp->next;
        }
        
        temp->val=temp->next->val;
        temp->next=temp->next->next;

        return head;
    }
};