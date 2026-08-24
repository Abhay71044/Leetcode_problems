class Solution {
public:

    bool issquare(int n){
        int x=sqrt(n);
        return x*x==n;
    }

    void solve(vector<int>& nums,vector<int>& output,vector<bool>& visited,int &count){
        if(output.size()==nums.size()){
            count++;
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]){
                continue;
            }
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            if(!output.empty()){
                int sum=output.back()+nums[i];
                if(!issquare(sum)){
                    continue;
                }
            }

            visited[i]=true;
            output.push_back(nums[i]);
            solve(nums,output,visited,count);
            output.pop_back();
            visited[i]=false;
        }
    }

    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>output;
        vector<bool>visited(nums.size(),false);
        int count=0;
        solve(nums,output,visited,count);
        return count;
    }
};