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

    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode* rev=reverse(head);
        ListNode* max=rev;
        ListNode* curr=rev->next;
        while(curr!=NULL){
            if(curr->val<max->val){
                max->next=curr->next;
            }
            else{
                max=curr;
            }
            curr=curr->next;
        }
        return reverse(rev);
    }
};