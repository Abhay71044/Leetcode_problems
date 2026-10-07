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

    ListNode* findmiddle(ListNode* head){
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

    void reorderList(ListNode* head) {
        ListNode* mid=findmiddle(head);
        ListNode* second=mid->next;
        mid->next=NULL;
        second=reverse(second);
        ListNode* first=head;
        while(first!=NULL && second!=NULL){
            ListNode* firstnext=first->next;
            ListNode* secondnext=second->next;
            first->next=second;
            second->next=firstnext;
            first=firstnext;
            second=secondnext;
        }
    }
};