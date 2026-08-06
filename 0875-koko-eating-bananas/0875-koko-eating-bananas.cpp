class Solution {
public:

    int maxEle(vector<int>&arr){
        int maxi=-1;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }

    long long totaltime(vector<int>&arr,int h){
        long long thr=0;
        for(int i=0;i<arr.size();i++){
            thr+=ceil((double)arr[i] / (double) h);
        }
        return thr;
    }

    int minEatingSpeed(vector<int>& arr, int h) {
        int low=1;
        int high=maxEle(arr);
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(totaltime(arr,mid)<=h){
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