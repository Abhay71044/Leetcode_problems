class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0;
        int count=0;
        while(i<n && i<target.size()){
            if(count+1 == target[i]){
                ans.push_back("Push");
                i++;
                count++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                count++;
            }
        }
        return ans;
    }
};