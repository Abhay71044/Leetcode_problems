class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(auto val:nums){
            mp[val]++;
        }
        while(mp.count(original)){
            original*=2;
        }
        return original;
    }
};