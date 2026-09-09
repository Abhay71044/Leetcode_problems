class Solution {
public:
    int maxSum(vector<int>& nums) {
        vector<int>arr;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int maxi=-1;
            while(a){
                maxi=max(maxi,a%10);
                a=a/10;
            }
            arr.push_back(maxi);
        }
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int sum=0;
                if(arr[i]==arr[j]){
                    ans=max(ans,nums[i]+nums[j]);
                }
            }
        }
        return ans;
    }
};