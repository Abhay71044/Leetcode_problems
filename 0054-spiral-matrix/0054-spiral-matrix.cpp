class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int totalelement=m*n;
        int startrow=0;
        int startcol=0;
        int endrow=m-1;
        int endcol=n-1;
        int count=0;
        vector<int>ans;
        while(count<totalelement){
            for(int i=startcol;i<=endcol && count<totalelement;i++){
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow && count<totalelement;i++){
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            for(int i=endcol;i>=startcol && count<totalelement;i--){
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow && count<totalelement;i--){
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return ans;
    }
};