class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(0);
            }
            else{
                int val=st.top();
                st.pop();
                int score;
                if(val==0) score=1;
                else score=2*val;
                st.top()+=score;
            }
        }
        return st.top();
    }
};