class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>a;
        int n=arr.size();
        int r=k;
        int i=0,j=1;
        while(k>0){
            if(i<n && arr[i]==j){
                ++i;
                ++j;
            }
            else{
                a.push_back(j);
                ++j;
                --k;
            }
        }
        return a[r-1];
    }
};