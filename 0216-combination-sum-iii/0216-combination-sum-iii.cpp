class Solution {
public:

    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&output,int k,int n,int idx){
        if(k==output.size() ){
            if(n==0){
                ans.push_back(output);
            }
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(nums[i]>n) break;
            output.push_back(nums[i]);
            solve(nums,ans,output,k,n-nums[i],i+1);
            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,ans,output,k,n,0);
        return ans;
    }
};