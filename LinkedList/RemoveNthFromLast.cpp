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
        ListNode *temp1=head;
        int s=0;
        while(temp1!=NULL){
            s++;
            temp1=temp1->next;
        }
        if(s==1 && n==1) return NULL;
        int k= s-n+1;
        if(k==1) return head->next;
        ListNode *temp=head;
        while(k-2 && temp!=NULL){
            temp=temp->next;
            k--;
        }
        if(temp!=NULL && temp->next != NULL) temp->next=temp->next->next;
        return head;
    }
};