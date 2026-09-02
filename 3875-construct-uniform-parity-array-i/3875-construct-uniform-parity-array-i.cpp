class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddcount=0,evencount=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0) evencount++;
            else oddcount++;
        }
        if(evencount==nums1.size()) return true;
        if(oddcount==nums1.size()) return true;
        return true;
    }
};