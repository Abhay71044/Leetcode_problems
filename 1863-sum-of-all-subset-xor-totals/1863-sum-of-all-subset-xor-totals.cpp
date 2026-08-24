class Solution {
public:
    int ans=0;

    void solve(vector<int>&nums,int i,int xr){
        if(i==nums.size()){
            ans+=xr;
            return;
        }
        solve(nums,i+1,xr^nums[i]);
        solve(nums,i+1,xr);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(nums,0,0);
        return ans;    
    }
};