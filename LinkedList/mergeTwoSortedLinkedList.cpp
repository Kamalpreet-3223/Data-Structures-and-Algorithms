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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL) return NULL;
        else if(l1==NULL && l2!=NULL) return l2;
        else if(l1!=NULL && l2==NULL) return l1;

        if(l1->val<l2->val){
            ListNode *n=mergeTwoLists(l1->next,l2);
            l1->next=n;
            return l1;
        }
        else{
            ListNode *n=mergeTwoLists(l1,l2->next);
            l2->next=n;
            return l2;
        }
    }
};