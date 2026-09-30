class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int countone=0;
        int countzero=0;
        for(int i=0;i<students.size();i++){
            if(students[i]==0){
                countzero++;
            }
            else{
                countone++;
            }
        }
        for(int i=0;i<sandwiches.size();i++){
            if(sandwiches[i] == 1){
                if(countone==0){
                    return sandwiches.size()-i;
                }
                else{
                    countone--;
                }
            }
            else{
                if(countzero==0){
                    return sandwiches.size()-i;
                }
                else{
                    countzero--;
                }
            }
        }
        return 0;
    }
};