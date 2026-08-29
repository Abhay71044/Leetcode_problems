class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool>isjewels(128,false);
        for(char ch:jewels){
            isjewels[ch]=true;
        }
        int count=0;
        for(char ch:stones){
            if(isjewels[ch]){
                count++;
            }
        }
        return count;
    }
};