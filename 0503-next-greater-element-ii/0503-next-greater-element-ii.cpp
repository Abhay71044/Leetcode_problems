class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans(nums.size());
        stack<int>st;
        st.push(-1);
        for(int i=2*nums.size()-1;i>=0;i--){
            int idx=i % nums.size();
            int curr=nums[idx];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }
            if(st.empty()){
                ans[idx]=-1;
            }
            else{
                ans[idx]=st.top();
            }
            st.push(curr);
        }
        return ans;
    }
};