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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL || head->next==NULL) return head;
        ListNode* temp=head,*temp2=head;
        int i=0;
        ListNode* ans;
        while(temp2->next!=NULL){
            i++;
            temp2=temp2->next;
        }
        i+=1;
        if(i!=0)k=k%i;
        if(k==0 || head==NULL || head->next==NULL) return head;
        int n=i-k-1;
        while(n--){
            temp=temp->next;
        }
        ans=temp->next;
        temp->next=NULL;
        temp2->next=head;
        
        return ans;
    }
};