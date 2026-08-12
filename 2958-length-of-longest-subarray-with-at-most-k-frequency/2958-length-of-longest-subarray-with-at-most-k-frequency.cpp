class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int maxi=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while (mp[nums[i]] > k) {
                mp[nums[left]]--;
                left++;
            }
            maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};