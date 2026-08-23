class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] % 6 == 0){
                total+=nums[i];
                count++;
            }
        }
        int ans=0;
        if(count!=0) ans=total/count;
        return ans;
    }
};