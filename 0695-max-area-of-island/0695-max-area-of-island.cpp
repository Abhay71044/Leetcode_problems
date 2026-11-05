class Solution {
public:

    void solve(int row,int col,vector<vector<int>>& visited,vector<vector<int>>& grid,int &ans){
        int area=1;
        int n=grid.size();
        int m=grid[0].size();
        visited[row][col]=1;
        queue<pair<int,int>>q;
        vector<int>delrow={1,-1,0,0};
        vector<int>delcol={0,0,-1,1};
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    visited[nrow][ncol]=1;
                    area++;
                    q.push({nrow,ncol});
                }
            }
        }
        if(area>ans){
            ans=area;
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)
                    solve(i,j,visited,grid,ans);
            }
        }
        return ans;
    }
};