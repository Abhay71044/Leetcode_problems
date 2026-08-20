class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int maxi=INT_MIN;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            int flag=1;
            for(int j=0;j<s.size();j++){
                if(isalpha(s[j])){
                    flag=0;
                    int b=s.size();
                    maxi=max(maxi,b);
                    break;
                }
            }
            if(flag==1){
                int a=stoi(s);
                maxi=max(maxi,a);
            }
        }
        return maxi;
    }
};