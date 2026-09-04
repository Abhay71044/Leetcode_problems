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

    int findLen(ListNode* head){
        int count=0;
        while(head!=NULL){
            head=head->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int len=findLen(head);
        int p=k%len;
        if(p==len) return head;
        int total=len-p;
        ListNode* temp=head;
        while(total>1){
            temp=temp->next;
            total--;
        }
        ListNode* last=head;
        while(last->next!=NULL){
            last=last->next;
        }
        last->next=head;
        ListNode* curr=temp->next;
        temp->next=NULL;
        head=curr;
        return head;
    }
};