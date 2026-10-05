class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int val=st.top();
                st.pop();
                int score;
                if(val==0) score=1;
                else score=val*2;
                st.top()+=score;
            }
        }
        return st.top();
    }
};