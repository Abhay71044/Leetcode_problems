class Solution {
public:

    bool isPalindrome(string&s,int low,int high){
        while(low<high){
            if(s[low]!=s[high]){
                return false;
            }
            low++;
            high--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(isPalindrome(s,i,j)){
                    string t=s.substr(i,j-i+1);
                    ans=t.size()>ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
};