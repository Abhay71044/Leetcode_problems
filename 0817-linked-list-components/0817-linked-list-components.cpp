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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int>st;
        for(auto val:nums){
            st.insert(val);
        }
        int count=0;
        while(head!=NULL){
            if(st.find(head->val) != st.end()){
                if(head->next==NULL || st.find(head->next->val) == st.end()){
                    count++;
                }
            }
            head=head->next;
        }
        return count;
    }
};