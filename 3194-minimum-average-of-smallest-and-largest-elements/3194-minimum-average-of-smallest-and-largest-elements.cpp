class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        double ans=INT_MAX;
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            double average=(nums[i]+nums[j])/2.0;
            ans=min(ans,average);
            i++;
            j--;
        }
        return ans;
    }
};