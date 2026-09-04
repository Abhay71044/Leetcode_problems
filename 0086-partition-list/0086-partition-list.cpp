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
        ListNode* small=new ListNode(-1);
        ListNode* newHead=small;
        ListNode* greater=new ListNode(-1);
        ListNode* greaterHead=greater;
        while(head!=NULL){
            if(head->val >= x){
                ListNode* temp=head;
                head=head->next;
                temp->next=NULL;
                greater->next=temp;
                greater=greater->next;
            }
            else{
                ListNode* temp=head;
                head=head->next;
                temp->next=NULL;
                small->next=temp;
                small=small->next;
            }
        }
        small->next=greaterHead->next;
        return newHead->next;
    }
};