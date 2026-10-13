class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]=-nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        long long mid=nums.size()/2;
        long long half1=0;
        long long half2=0;
        for(int i=0;i<mid;i++){
            half1+=nums[i]*nums[i];
        }
        for(int i=mid;i<nums.size();i++){
            half2+=nums[i]*nums[i];
        }
        return half2-half1;
    }
};