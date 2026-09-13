class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(st.empty()){
                st.push(ch);
            }
            else{
                if(ch=='a'){
                    if(st.top() == 'b'){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
                else{
                    if(st.top() == 'a'){
                        st.pop();
                    }
                    else{
                        st.push(ch);
                    }
                }
            }
        }
        return st.size();
    }
};