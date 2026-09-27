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
            ListNode* temp = head;
            
            int sz = 1;
            while(temp->next!=nullptr){
                sz++;
                temp=temp->next;
            }

            int del= sz-n;
            int pos=0;

            if(head==NULL){
                return head;
            }

            if (del == 0) {
                ListNode* toDelete = head;
                head = head->next;
                delete toDelete;
                return head;
            }

            ListNode* temp1 = head;
            for (int i = 0; i < del - 1; ++i) {
                temp1 = temp1->next;
            }
    
            ListNode* toDelete = temp1->next;
            temp1->next = temp1->next->next;
            delete toDelete;
        return head;
    }
};