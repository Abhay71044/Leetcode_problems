class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int totalelements=m*n;
        int count=0;
        vector<int>ans;

        int top=0;
        int bottom=m-1;
        int left=0;
        int right=n-1;
        while(count<totalelements){
            for(int i=left;i<=right && count<totalelements;i++){
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            for(int i=top;i<=bottom && count<totalelements;i++){
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            for(int i=right;i>=left && count<totalelements;i--){
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;
            for(int i=bottom;i>=top && count<totalelements;i--){
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }
};