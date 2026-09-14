class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int maxi = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= maxi) {
                ans++;
                maxi = nums[i];
            }
        }
        return ans;
    }
};