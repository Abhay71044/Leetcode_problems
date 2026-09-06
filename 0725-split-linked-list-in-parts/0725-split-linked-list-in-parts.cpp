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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        ListNode* temp=head;
        int len=0;
        while(temp != NULL){
            temp=temp->next;
            len++;
        }
        int size=len/k;
        int extra=len%k;
        temp=head;
        for(int i=0;i<k;i++){
            ListNode* parthead=temp;
            int currSize = size;
            if(extra > 0) {
                currSize++;
                extra--;
            }
            for(int j=1;j<currSize;j++){
                if(temp!=NULL){
                    temp=temp->next;
                }
            }
            if(temp != NULL) {
                ListNode* nextPart = temp->next;
                temp->next = NULL;
                temp = nextPart;
            }
            ans.push_back(parthead);
        }
        return ans;
    }
};