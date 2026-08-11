class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        int ans=0;
        vector<bool>prime(n,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<n;i++){
            if(prime[i]){
                ans++;
                int j=2*i;
                while(j<n){
                    prime[j]=false;
                    j=j+i;
                }
            }
        }
        return ans;
    }
};