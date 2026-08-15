class Solution {
public:

    void solve(string& num1,string& num2,int i,int j,int carry ,string&ans){
        if(i<0 && j<0){
            if(carry != 0){
                ans.push_back(carry+'0');
            }
            return ;
        }

        int n1=(i>=0 ? num1[i] : '0')-'0';
        int n2=(j>=0 ? num2[j] : '0')-'0';
        int csum=n1+n2+carry;
        int digit=csum%10;
        carry=csum/10;
        ans.push_back(digit+'0');

        solve(num1,num2,i-1,j-1,carry,ans);
    }

    string addStrings(string num1, string num2) {
        string ans="";
        solve(num1,num2,num1.size()-1,num2.size()-1,0,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};