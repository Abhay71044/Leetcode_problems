class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c1=s[0];
        char c2=s[3];
        int r1=s[1]-'0';
        int r2=s[4]-'0';
        vector<string>ans;
        for(char col=c1;col<=c2;col++){
            for(int row=r1;row<=r2;row++){
                ans.push_back(string(1,col) + to_string(row));
            }
        }
        return ans;
    }
};