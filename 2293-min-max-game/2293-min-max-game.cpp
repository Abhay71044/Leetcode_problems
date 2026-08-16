class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()>1){
            vector<int> temp;
            for (int i = 0; i < nums.size(); i += 2) {
                if ((i / 2) % 2 == 0) {
                    temp.push_back(min(nums[i], nums[i + 1]));
                }
                else {
                    temp.push_back(max(nums[i], nums[i + 1]));
                }
            }
            nums = temp;
        }
        return nums[0];
    }
};