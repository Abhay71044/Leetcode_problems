class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int startrow = 0, endrow = m - 1;
        int startcol = 0, endcol = n - 1;
        while (head != NULL && startrow <= endrow && startcol <= endcol) {
            for (int i = startcol; i <= endcol && head != NULL; i++) {
                ans[startrow][i] = head->val;
                head = head->next;
            }
            startrow++;
            for (int i = startrow; i <= endrow && head != NULL; i++) {
                ans[i][endcol] = head->val;
                head = head->next;
            }
            endcol--;
            if (startrow <= endrow) {
                for (int i = endcol; i >= startcol && head != NULL; i--) {
                    ans[endrow][i] = head->val;
                    head = head->next;
                }
                endrow--;
            }
            if (startcol <= endcol) {
                for (int i = endrow; i >= startrow && head != NULL; i--) {
                    ans[i][startcol] = head->val;
                    head = head->next;
                }
                startcol++;
            }
        }
        return ans;
    }
};