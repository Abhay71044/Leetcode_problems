class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count=0;
        while(true){
            bool sorted=true;
            for(int i=0;i<nums.size()-1;i++){
                if(nums[i]>nums[i+1]){
                    sorted=false;
                    break;
                }
            }
            if(sorted) break;
            int minSum = INT_MAX;
            int idx = -1;
            for (int i = 0; i + 1 < (int)nums.size(); i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }
            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            count++;

        }
        return count;
    }
};