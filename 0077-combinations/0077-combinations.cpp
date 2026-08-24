class Solution {
public:

    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&output,int k,int idx){
        if(output.size()==k){
            ans.push_back(output);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            output.push_back(nums[i]);
            solve(nums,ans,output,k,i+1);
            output.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,ans,output,k,0);
        return ans;
    }
};