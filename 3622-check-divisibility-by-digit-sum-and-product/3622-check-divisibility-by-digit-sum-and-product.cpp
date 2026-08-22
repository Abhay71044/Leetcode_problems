class Solution {
public:
    bool checkDivisibility(int n) {
        long long sum=0;
        long long pro=1;
        int temp=n;
        while(temp){
            sum=sum+temp%10;
            pro=pro*(temp%10);
            temp=temp/10;
        }
        long long total=sum+pro;
        if(n % total == 0) return true;
        return false;
    }
};