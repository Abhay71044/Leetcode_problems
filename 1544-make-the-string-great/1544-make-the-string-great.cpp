class Solution {
public:
    string makeGood(string s) {
        if(s.size()<2) return s;
        stack<char>st;
        for(auto ch:s){
            if (!st.empty() && (st.top() == tolower(ch) || st.top() == toupper(ch)) && st.top() != ch){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};