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
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head,*fast=head;
        slow=slow->next;
        if(fast==NULL || fast->next==NULL) return NULL;
        else{
            fast=fast->next->next;
        }
        while(fast!=slow){
            slow=slow->next;
            if(fast==NULL || fast->next==NULL) return NULL;
            else{
                fast=fast->next->next;
            }
        }
        ListNode *temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }
        return temp;
    }
};