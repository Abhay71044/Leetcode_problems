class Solution {
public:

    void solve(vector<string>&ans,string output,vector<string>&mapping,string s,int idx){
        if(idx>=s.size()){
            ans.push_back(output);
            return;
        }
        int digit=s[idx]-'0';
        string value=mapping[digit];
        for(int i=0;i<value.size();i++){
            char ch=value[i];
            output.push_back(ch);
            solve(ans,output,mapping,s,idx+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string>ans;
        string output="";
        vector<string>mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(ans,output,mapping,digits,0);
        return ans;
    }
};