class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddCount = 0, evenCount = 0;
        int minOdd = INT_MAX, minEven = INT_MAX;
        for (int x : nums1) {
            if (x % 2 == 0) {
                evenCount++;
                minEven = min(minEven, x);
            } else {
                oddCount++;
                minOdd = min(minOdd, x);
            }
        }
        if (oddCount == 0 || evenCount == 0) return true;
        return minOdd < minEven;
    }
};