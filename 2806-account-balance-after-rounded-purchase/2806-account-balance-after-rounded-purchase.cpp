class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int ans = purchaseAmount / 10;
        if(purchaseAmount % 10 >= 5)
            ans++;
        int a = ans * 10;
        return 100 - a;
    }
};