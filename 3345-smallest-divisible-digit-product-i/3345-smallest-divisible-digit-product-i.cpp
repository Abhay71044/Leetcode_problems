class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int x=n;x<=100;x++){
            int p=1;
            int temp=x;
            while(temp>0){
                p=p*(temp%10);
                temp=temp/10;
            }
            if(p%t==0){
                return x;
            }
        }
        return 0;
    }
};