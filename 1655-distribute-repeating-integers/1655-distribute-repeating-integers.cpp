class Solution {
public:

    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity,int ithcustomer){
        if(ithcustomer == quantity.size()){
            return true;
        }

        for(int i=0;i<counts.size();i++){
            if(counts[i]>=quantity[ithcustomer]){
                counts[i]-=quantity[ithcustomer];
                if(canDistributeHelper(counts,quantity,ithcustomer+1)){
                    return true;
                }
                counts[i]+=quantity[ithcustomer];
            }
        }
        return false;
    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int>mp;
        for(auto num:nums)
            mp[num]++;
        vector<int>counts;
        for(auto it: mp)
            counts.push_back(it.second);
        sort(quantity.rbegin(),quantity.rend());
        return canDistributeHelper(counts,quantity,0);
    }
};