class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for(char ch:s){
            if(!st.empty() && st.top().first==ch){
                st.top().second++;

                if(st.top().second == k){
                    st.pop();
                }
            }
            else{
                st.push({ch,1});
            }
        }
        string ans="";
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            ans = string(p.second, p.first) + ans;
        }
        return ans;
    }
};