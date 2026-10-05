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

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        if(left==right) return head;
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* newhead=prev;
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }
        ListNode* curr=prev->next;
        prev->next=NULL;
        ListNode* last=curr;
        for(int i = left; i < right; i++) {
            last = last->next;
        }
        ListNode* forward=last->next;
        last->next=NULL;
        ListNode* temp=reverse(curr);
        prev->next=temp;
        curr->next=forward;
        return newhead->next;
    }
};