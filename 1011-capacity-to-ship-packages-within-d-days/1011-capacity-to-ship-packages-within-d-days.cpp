class Solution {
public:

    int maxele(vector<int>& weights){
        int maxi=-1;
        for(int i=0;i<weights.size();i++){
            maxi=max(weights[i],maxi);
        }
        return maxi;
    }

    int capacity(vector<int>& weights,int cap){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                day=day+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=maxele(weights);
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(capacity(weights,mid)<=days){
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