class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());
        for(int i=0;i<prices.size();i++){
            int j=i+1;
            int flag=0;
            while(j<prices.size()){
                if(prices[j]<=prices[i]){
                    flag=1;
                    ans[i]=prices[i]-prices[j];
                    break;
                }
                j++;
            }
            if(flag==0){
                ans[i]=prices[i];
            }
        }
        return ans;
    }
};