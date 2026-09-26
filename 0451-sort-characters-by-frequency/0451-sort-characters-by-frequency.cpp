class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
        }
        vector<pair<char, int>> v;
        for(auto x : mp) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string ans="";
        for(auto x:v){
            int a=x.second;
            while(a--){
                ans+=x.first;
            }
        }
        return ans;
    }
};