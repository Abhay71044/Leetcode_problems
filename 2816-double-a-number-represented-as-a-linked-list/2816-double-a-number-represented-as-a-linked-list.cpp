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

    ListNode* doubleIt(ListNode* head) {
        ListNode* rev = reverse(head);
        ListNode* curr = rev;
        ListNode* prevNode = nullptr;
        int carry = 0;
        while (curr != nullptr) {
            int val = curr->val * 2 + carry;
            curr->val = val % 10;
            carry = val / 10;
            prevNode = curr;
            curr = curr->next;
        }
        if (carry > 0) {
            prevNode->next = new ListNode(carry);
        }
        return reverse(rev);
    }
};