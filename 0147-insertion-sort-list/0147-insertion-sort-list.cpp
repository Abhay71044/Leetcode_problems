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

        ListNode* findMiddle(ListNode* head){
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        if(left==NULL) return right;
        if(right==NULL) return left;
        ListNode* ans=new ListNode(-1);
        ListNode* mptr=ans;
        while(left!=NULL && right!=NULL){
            if(left->val <= right->val){
                mptr->next=left;
                mptr=left;
                left=left->next;
            }
            else{
                mptr->next=right;
                mptr=right;
                right=right->next;
            }
        }
        if(left!=NULL){
            mptr->next=left;
        }
        if(right!=NULL){
            mptr->next=right;
        }
        return ans->next;
    }

    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* mid=findMiddle(head);
        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        left=insertionSortList(left);
        right=insertionSortList(right);

        ListNode* mergeLL=merge(left,right);
        return mergeLL;
    }
};