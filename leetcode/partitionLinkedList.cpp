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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL) return NULL;
        ListNode* dummy = new ListNode(-100);
        dummy->next = head;
        ListNode* node=dummy;
        ListNode* i=dummy;
        if(dummy->next->val < x){
            node=dummy->next;
            i=dummy->next;
        }
        while(node->next != NULL){
            if(node->next->val < x && node->val>=x){
                ListNode* nextNode = node->next->next;
                node->next->next = i->next;
                i->next = node->next;
                node->next = nextNode;
                i=i->next;
            }
            else if(node->next->val < x && node->val<x){
                node=node->next;
                i=i->next;
            }
            else{
                node=node->next;
            }
        }

        return dummy->next;

    }
};