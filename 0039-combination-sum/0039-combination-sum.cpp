class Solution {
public:

    void solve(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&output,int idx){
        if(target==0){
            ans.push_back(output);
            return ;
        }
        if(target<0){
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            output.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,output,i);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(candidates,target,ans,output,0);
        return ans;
    }
};