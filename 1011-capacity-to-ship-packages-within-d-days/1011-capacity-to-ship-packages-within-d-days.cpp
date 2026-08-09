class Solution {
public:

    int numberOfDays(vector<int>&arr,int d){
        int sum=0;
        int count=1;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>d){
                count++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
        return count;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        for(int i=0;i<weights.size();i++){
            low=max(low,weights[i]);
            high=high+weights[i];
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(numberOfDays(weights,mid) <= days){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};