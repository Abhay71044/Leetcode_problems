class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int twice = 0;
        int missing = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                twice = nums[i];
            }
            if (nums[i] == missing) {
                missing++;
            }
        }
        return {twice, missing};
    }
};