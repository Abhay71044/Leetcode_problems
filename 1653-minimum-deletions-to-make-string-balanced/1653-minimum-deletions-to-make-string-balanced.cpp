class Solution {
public:
    int minimumDeletions(string s) {
        int b=0;
        int deletion=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='b'){
                b++;
            }
            else{
                deletion=min(deletion+1,b);
            }
        }
        return deletion;
    }
};