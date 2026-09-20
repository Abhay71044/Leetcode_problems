class Solution {
public:
    int reverseDegree(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            int a='z'-s[i]+1;
            count+=a*(i+1);
        }
        return count;
    }
};