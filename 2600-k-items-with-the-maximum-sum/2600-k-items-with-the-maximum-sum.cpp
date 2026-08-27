class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int sum=0;
        if(k<=numOnes){
            return k;
        }
        else{
            if(k<=(numOnes+numZeros)){
                return numOnes;
            }
            else{
                int neg=k-(numOnes+numZeros);
                sum=numOnes-neg;
            }
        }
        return sum;
    }
};