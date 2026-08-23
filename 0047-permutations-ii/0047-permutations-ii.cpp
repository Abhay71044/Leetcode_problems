class Solution {
public:

    void permutation(vector<int>&nums,set<vector<int>>&st,int i){
        if(i==nums.size()){
            st.insert(nums);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            permutation(nums,st,i+1);
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        permutation(nums,st,0);
        vector<vector<int>>ans;
        for(auto val:st){
            ans.push_back(val);
        }
        return ans;
    }
};