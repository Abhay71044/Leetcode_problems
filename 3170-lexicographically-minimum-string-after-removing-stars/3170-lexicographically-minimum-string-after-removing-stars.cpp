class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> pos(26);
        vector<bool> removed(s.size(), false);

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch != '*') {
                pos[ch - 'a'].push(i);
            } else {
                removed[i] = true;
                for (int c = 0; c < 26; c++) {
                    if (!pos[c].empty()) {
                        removed[pos[c].top()] = true;
                        pos[c].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (!removed[i]) ans.push_back(s[i]);
        }
        return ans;
    }
};