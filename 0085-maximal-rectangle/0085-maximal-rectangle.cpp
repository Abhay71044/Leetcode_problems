class Solution {
public:

    vector<int> nextSmallerElement(vector<int>& s){
    vector<int>ans(s.size());
    stack<int>st;
    st.push(-1);
    for(int i=s.size()-1;i>=0;i--){
        int curr=s[i];
        while(st.top()!=-1 && s[st.top()]>=curr){
        st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
    }

    vector<int> prevSmallerElement(vector<int>s){
    vector<int>ans(s.size());
    stack<int>st;
    st.push(-1);
    for(int i=0;i<s.size();i++){
        int curr=s[i];
        while(st.top()!=-1 && s[st.top()]>=curr){
        st.pop();
        }
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=prevSmallerElement(heights);
        vector<int>next=nextSmallerElement(heights);
        int maxarea=INT_MIN;
        int size=heights.size();

        for(int i=0;i<heights.size();i++){
            int length=heights[i];
            if(next[i]==-1){
            next[i]=size;
            }
            int width=next[i]-prev[i]-1;
            int area=length*width;
            maxarea=max(maxarea,area);

        }
        return maxarea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>>v;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            vector<int>t;
            for(int j=0;j<m;j++){
                t.push_back(matrix[i][j]-'0');
            }
            v.push_back(t);
        }
        int area=largestRectangleArea(v[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]){
                    v[i][j]+=v[i-1][j];
                }
                else{
                    v[i][j]=0;
                }
            }
            area=max(area,largestRectangleArea(v[i]));
        }
        return area;
    }
};