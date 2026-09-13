class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isalpha(ch)){
                st.push(ch);
            }
            else{
                if(!st.empty())
                    st.pop();
            }
        }
        if(st.empty()) return "";
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};