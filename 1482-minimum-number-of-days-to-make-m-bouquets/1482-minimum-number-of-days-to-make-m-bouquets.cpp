class Solution {
public:

    bool possible(vector<int>arr,int day,int m,int k){
        int count=0;
        int noOfB=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day) count++;
            else{
                noOfB+=(count/k);
                count=0;
            }
        }
        noOfB+=(count/k);
        return noOfB>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(bloomDay.size()<val) return -1;
        int low=INT_MAX;
        int high=INT_MIN;
        for(int i=0;i<bloomDay.size();i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
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