class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int>ans(m+n);
        int left=0;
        int right=0;
        int curr=0;
        while(left<m && right<n){
            if(nums1[left]<=nums2[right]){
                ans[curr++]=nums1[left++];
            }
            else{
                ans[curr++]=nums2[right++];
            }
        }
        while(left<m){
            ans[curr++]=nums1[left++];
        }
        while(right<n){
            ans[curr++]=nums2[right++];
        }
        int total=m+n;
        return (((ans[(total-1)/2])+ans[total/2])/2.0);
    }
};