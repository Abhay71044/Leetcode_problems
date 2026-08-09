class Solution {
public:
    string largestOddNumber(string num) {
        int ind=-1;
        int i=num.size()-1;
        while(i>=0){
            if((num[i]-'0') % 2 == 1){
                ind=i;
                break;
            }
            i--;
        }
        i=0;
        while(i>=ind && num[i]=='0') i++;
        return num.substr(i,ind-i+1);
    }
};