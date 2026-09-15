class Solution {
public:
    int addMinimum(string word) {
        int i=0;
        int count=0;
        while(i<word.size()){
            if(word[i] == 'a'){
                i++;
            }
            else{
                count++;
            }
            if(i<word.size() && word[i] == 'b'){
                i++;
            }
            else{
                count++;
            }
            if(i<word.size() && word[i] == 'c'){
                i++;
            }
            else{
                count++;
            }
        }
        return count;
    }
};