class Solution {
public:

bool issafe(vector<vector<char>>&board,int col,int row,int n){
        int i=row;
        int j=col;
        //check row
        while(j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            j--;
        }
        i=row;
        j=col;
        //check upper diagonal
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i--;
            j--;
        }
        i=row;
        j=col;
        //check lowerdiagonal
        while(i<n && j>=0){
            if(board[i][j]=='Q'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    void solve(vector<vector<char>>&board,int col,int n,vector<vector<string>>&ans){
        if(col>=n){
            vector<string>temp;
            for(int i=0;i<n;i++){
                string output="";
                for(int j=0;j<n;j++){
                    output+=board[i][j];
                }
                temp.push_back(output);
            }
            ans.push_back(temp);
            return;
        }

        for(int row=0;row<n;row++){
            if(issafe(board,col,row,n)){
                board[row][col]='Q';
                solve(board,col+1,n,ans);
                board[row][col]='.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col=0;
        vector<vector<string>>ans;
        solve(board,col,n,ans);
        return ans.size();
    }
};