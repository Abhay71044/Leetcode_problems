class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minindx=0;
        int mini=INT_MAX;
        int maxindx=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(mini>nums[i]){
                mini=nums[i];
                minindx=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                maxindx=i;
            }
        }
        int i = min(minindx, maxindx);
        int j = max(minindx, maxindx);
        int bothFront = j + 1;
        int bothBack  = n - i;
        int oneEach   = (i + 1) + (n - j);
        return min({bothFront, bothBack, oneEach});
    }
};