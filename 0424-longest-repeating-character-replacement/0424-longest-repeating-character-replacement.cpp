class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int ans=0;
        int maxf=0;
        vector<int>freq(26,0);
        for(int r=0;r<s.size();r++){
            freq[s[r]-'A']++;
            maxf=max(maxf,freq[s[r]-'A']);
            while((r-l+1)-maxf >k){
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l);
        }
        return ans+1;
    }
};