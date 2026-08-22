class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto val:nums){
            mp[val]++;
        }
        sort(nums.begin(),nums.end());
        int maxi=-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<0){
                break;
            }
            if(maxi<nums[i]){
                if(mp.find(-nums[i]) != mp.end()){
                    maxi=nums[i];
                }
            }
        }
        return maxi;
    }
};