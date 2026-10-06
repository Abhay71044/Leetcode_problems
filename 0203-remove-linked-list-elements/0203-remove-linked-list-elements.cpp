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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev=new ListNode(-1);
        prev->next=head;
        ListNode* newhead=prev;
        ListNode* curr=head;
        while(curr!=NULL){
            if(curr->val==val){
                ListNode* temp=curr;
                prev->next=curr->next;
                curr=curr->next;
                temp->next=NULL;
                delete temp;
            }
            else{
                curr=curr->next;
                prev=prev->next;
            }
        }
        return newhead->next;
    }
};