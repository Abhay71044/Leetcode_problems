class Solution {
public:

    vector<int> prevSmaller(vector<int>& heights){
        stack<int>st;
        vector<int>ans(heights.size());
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& heights){
        stack<int>st;
        vector<int>ans(heights.size());
        st.push(-1);
        for(int i=heights.size()-1;i>=0;i--){
            int curr=heights[i];
            while(st.top()!=-1 && heights[st.top()]>=curr){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>next=nextSmaller(heights);
        vector<int>prev=prevSmaller(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int len=heights[i];
            if(next[i] == -1){
                next[i] = heights.size();
            }
            int wid=next[i]-prev[i]-1;
            int ans=len*wid;
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};