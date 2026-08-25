class Solution {
public:

    void combination_sumhelper(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&v,int index){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;
            v.push_back(candidates[i]);
            combination_sumhelper(candidates,target-candidates[i],ans,v,i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        combination_sumhelper(candidates,target,ans,v,0);
        return ans;
    }
};