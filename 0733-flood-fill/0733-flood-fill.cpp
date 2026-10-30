class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>&ans,vector<int>&delrow,vector<int>&delcol,int color,vector<vector<int>>&image,int inicolor){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]==inicolor){
                dfs(nrow,ncol,ans,delrow,delcol,color,image,inicolor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans=image;
        int inicolor=image[sr][sc];
        if(inicolor==color) return ans;
        vector<int>delrow={-1,1,0,0};
        vector<int>delcol={0,0,-1,1};
        dfs(sr,sc,ans,delrow,delcol,color,image,inicolor);
        return ans;
    }
};