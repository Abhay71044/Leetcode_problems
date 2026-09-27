class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1'){
                if(carry){
                    ans.push_back('1');
                    carry=1;
                }
                else{
                    ans.push_back('0');
                    carry=1;
                }
            }
            else if(a[i]=='0' && b[j]=='0'){
                if(carry){
                    ans.push_back('1');
                    carry=0;
                }
                else{
                    ans.push_back('0');
                    carry=0;
                }
            }
            else{
                if(carry){
                    ans.push_back('0');
                    carry=1;
                }
                else{
                    ans.push_back('1');
                    carry=0;
                }
            }
            i--;
            j--;
        }
        while(i>=0){
            int sum = (a[i]-'0') + carry;
            ans.push_back((sum%2)+'0');
            carry = sum/2;
            i--;
        }

        while(j>=0){
            int sum = (b[j]-'0') + carry;
            ans.push_back((sum%2)+'0');
            carry = sum/2;
            j--;
        }
        if(carry){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};