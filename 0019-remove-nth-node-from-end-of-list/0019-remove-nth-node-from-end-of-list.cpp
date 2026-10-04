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

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=findlen(head);
        int k=len-n;
        if(n==len){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        ListNode* temp=head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        ListNode* curr=temp->next;
        temp->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};