class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<long long> val(nums.begin(), nums.end());
        vector<int> prv(n), nxt(n);
        for (int i = 0; i < n; i++) {
            prv[i] = i - 1;
            nxt[i] = (i + 1 < n) ? i + 1 : -1;
        }
        multiset<pair<long long,int>> pairs;
        int bad = 0;
        for (int i = 0; i < n; i++) {
            if (nxt[i] != -1) {
                pairs.insert({val[i] + val[nxt[i]], i});
                if (val[i] > val[nxt[i]]) bad++;
            }
        }
        int ops = 0;
        while (bad > 0) {
            auto it = pairs.begin();
            int i = it->second;
            pairs.erase(it);
            int j = nxt[i];
            int p = prv[i];
            int q = nxt[j];
            if (val[i] > val[j]) bad--;
            if (p != -1) {
                pairs.erase(pairs.find({val[p] + val[i], p}));
                if (val[p] > val[i]) bad--;
            }
            if (q != -1) {
                pairs.erase(pairs.find({val[j] + val[q], j}));
                if (val[j] > val[q]) bad--;
            }
            val[i] += val[j];
            nxt[i] = q;
            if (q != -1) prv[q] = i;
            if (p != -1) {
                pairs.insert({val[p] + val[i], p});
                if (val[p] > val[i]) bad++;
            }
            if (q != -1) {
                pairs.insert({val[i] + val[q], i});
                if (val[i] > val[q]) bad++;
            }
            ops++;
        }
        return ops;
    }
};