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
    ListNode* reverse(ListNode * head){
        ListNode *p=NULL;
        ListNode *c=head,*n=head->next;
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL) n=n->next;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* reverseHead=reverse(slow->next);
        slow->next=reverseHead;
        ListNode* temp1=head;
        ListNode* temp=slow->next;
        while(temp!=NULL){
            if(temp1->val!=temp->val) return false;
            temp1=temp1->next;
            temp=temp->next;
        }
        
        return true;
    }
};