class Solution {
public:

    void bfs(int row, int col,vector<vector<int>>& grid,vector<vector<int>>& visited){
        int n=grid.size();
        int m=grid[0].size();
        vector<int>delrow={-1,1,0,0};
        vector<int>delcol={0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({row,col});
        visited[row][col]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 &&ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==0){
                        bfs(i,j,grid,visited);
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && visited[i][j]==0){
                    count++;
                    bfs(i,j,grid,visited);
                }
            }
        }
        return count;
    }
};