class Solution {
public:

    int maxEle(vector<int>&arr){
        int maxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }

    int possible(vector<int>&arr,int d){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum += ceil((double)arr[i] / d);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& arr, int threshold) {
        int low=1;
        int high=maxEle(arr);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(arr,mid)<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};