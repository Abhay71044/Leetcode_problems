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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        while(curr!=NULL){
            int a=prev->val;
            int b=curr->val;
            int ans=gcd(a,b);
            ListNode* newNode=new ListNode(ans);
            prev->next=newNode;
            newNode->next=curr;
            prev=curr;
            curr=curr->next;
        }
        return head;
    }
};