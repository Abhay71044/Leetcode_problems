class Solution {
public:

    vector<int> nextsmaller(vector<int>&heights){
        stack<int>st;
        vector<int>ans(heights);
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

    vector<int> prevsmaller(vector<int>&heights){
        vector<int>ans(heights.size());
        stack<int>st;
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

    int largestRectangleArea(vector<int>& heights) {
        vector<int>next=nextsmaller(heights);
        vector<int>prev=prevsmaller(heights);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            if(next[i]==-1){
                next[i]=heights.size();
            }
            int a=next[i];
            int b=prev[i];
            int wid=next[i]-prev[i]-1;
            int len=heights[i];
            int area=wid*len;
            maxi=max(maxi,area);
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        for(int i=0;i<matrix.size();i++){
            vector<int>t;
            for(int j=0;j<matrix[0].size();j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int maxi=largestRectangleArea(v[0]);
        for(int i=1;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            int ans=
            maxi=max(maxi,largestRectangleArea(v[i]));
        }
        return maxi;
    }
};