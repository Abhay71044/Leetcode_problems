class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        set<int>st;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            st.insert(sum);
            i++;
            j--;
        }
        return st.size();
    }
};