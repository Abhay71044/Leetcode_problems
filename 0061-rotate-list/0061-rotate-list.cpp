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

    int findlen(ListNode* head){
        int count=0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int len=findlen(head);
        k=k % len;
        if(k==len || k==0) return head;
        k=len-k;
        ListNode* temp=head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        ListNode* newhead=temp->next;
        ListNode* last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=head;
        temp->next=NULL;
        return newhead;
    }
};