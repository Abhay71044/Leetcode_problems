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
    ListNode* partition(ListNode* head, int x) {
        ListNode* smaller=new ListNode(-1);
        ListNode* smallhead=smaller;
        ListNode* greater=new ListNode(-1);
        ListNode* greaterhead=greater;
        while(head!=NULL){
            if(head->val<x){
                ListNode* temp=head;
                head=head->next;
                temp->next=NULL;
                smaller->next=temp;
                smaller=smaller->next;
            }
            else{
                ListNode* temp=head;
                head=head->next;
                temp->next=NULL;
                greater->next=temp;
                greater=greater->next;
            }
        }
        smaller->next=greaterhead->next;
        return smallhead->next;
    }
};