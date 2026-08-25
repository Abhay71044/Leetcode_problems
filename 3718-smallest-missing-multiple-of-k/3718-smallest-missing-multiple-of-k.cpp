class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto val:nums){
            mp[val]++;
        }
        int m=k;
        while(true){
            if (mp.find(k) == mp.end()) {
                return k;
            }
            k=k+m;
        }
        return -1;
    }
};