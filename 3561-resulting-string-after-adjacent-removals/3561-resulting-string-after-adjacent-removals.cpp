class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(st.empty()) st.push(ch);
            else{
                if(!st.empty() && (abs(st.top() - ch) == 1 || abs(st.top() - ch) == 25)){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};