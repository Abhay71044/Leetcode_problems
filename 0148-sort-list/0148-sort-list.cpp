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

    ListNode* findmidlle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                slow=slow->next;
                fast=fast->next;
            }
        }
        return slow;
    }

    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(left!=NULL && right!=NULL){
            if(left->val < right->val){
                curr->next=left;
                curr=left;
                left=left->next;
            }
            else{
                curr->next=right;
                curr=right;
                right=right->next;
            }
        }
        if(left!=NULL){
            curr->next=left;
            curr=left;
            left=left->next;
        }
        if(right!=NULL){
            curr->next=right;
            curr=right;
            right=right->next;
        }
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findmidlle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;
        left=sortList(left);
        right=sortList(right);
        ListNode* mergeLL=merge(left,right);
        return mergeLL;
    }
};