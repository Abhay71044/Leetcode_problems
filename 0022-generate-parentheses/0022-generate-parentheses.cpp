class Solution {
public:

    void solve(vector<string>&ans,int open,int closed,string output){
        if(open==0 && closed==0){
            ans.push_back(output);
            return;
        }
        if(open>0){
            output.push_back('(');
            solve(ans,open-1,closed,output);
            output.pop_back();
        }
        if(closed>open){
            output.push_back(')');
            solve(ans,open,closed-1,output);
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output;
        solve(ans,n,n,output);
        return ans;
    }
};