class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<=nums.size()-k;i++){
            set<int>st;
            for(int j=i;j<k+i;j++){
                st.insert(nums[j]);
            }
            for(int val:st){
                mp[val]++;
            }
        }
        int maxi=-1;
        for(auto it:mp){
            if(it.second==1){
                maxi=max(maxi,it.first);
            }
        }
        return maxi;
    }
};