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

    int findLen(ListNode* &head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return NULL;
        int len=findLen(head);
        int i=len-n;
        if(n == len){
            ListNode* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
            return head;
        }
        ListNode* temp=head;
        while(i>1){
            temp=temp->next;
            i--;
        }
        ListNode* curr=temp->next;
        temp->next=curr->next;
        curr->next=NULL;
        delete curr;
        return head;
    }
};