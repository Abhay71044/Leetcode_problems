class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch:s){
            if(ch == ']'){
                string stringToRepeat = "";
                while(!st.empty() && st.top() != "["){
                    string top=st.top();
                    stringToRepeat = top + stringToRepeat;
                    st.pop();
                }
                st.pop();
                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes = st.top() + numericTimes;
                    st.pop();
                }
                int n=stoi(numericTimes);

                string currentdecode="";
                while(n--){
                    currentdecode+=stringToRepeat;
                }
                st.push(currentdecode);
            }
            else{
                string temp(1,ch);
                st.push(temp);
            }
        } 
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};