class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size()+nums2.size());
        int n=nums1.size();
        int m=nums2.size();
        int leftindex=0;
        int rightindex=0;
        int k=0;
        while(leftindex<n && rightindex<m){
            if(nums1[leftindex]<nums2[rightindex]){
                ans[k++]=nums1[leftindex++];
            }
            else{
                ans[k++]=nums2[rightindex++];
            }

        }
        while(leftindex<n){
            ans[k++]=nums1[leftindex++];
        }
        while(rightindex<m){
            ans[k++]=nums2[rightindex++];
        }
        int total = n + m;
        return (ans[(total - 1) / 2] + ans[total / 2]) / 2.0;
    }
};