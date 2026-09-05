/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=NULL && b!=NULL){
            a=a->next;
            b=b->next;
        }
        if(a==NULL){
            int blen=0;
            while(b!=NULL){
                b=b->next;
                blen++;
            }
            while(blen--){
                headB=headB->next;
            }
        }
        if(b==NULL){
            int alen=0;
            while(a!=NULL){
                a=a->next;
                alen++;
            }
            while(alen--){
                headA=headA->next;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};