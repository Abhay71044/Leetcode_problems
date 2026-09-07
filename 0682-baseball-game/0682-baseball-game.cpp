class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto val : operations) {
            if(val == "C") {
                st.pop();
            }
            else if(val == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
            }
            else if(val == "D") {
                st.push(st.top() * 2);
            }
            else {
                st.push(stoi(val));
            }
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};