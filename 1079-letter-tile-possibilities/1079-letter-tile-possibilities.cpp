class Solution {
public:

    void solve(string tiles, set<string>& st, string output) {
        if (!output.empty()) {
            st.insert(output);
        }
        for (int i = 0; i < tiles.size(); i++) {
            char ch = tiles[i];
            string remaining = tiles.substr(0, i) + tiles.substr(i + 1);
            solve(remaining, st, output + ch);
        }
    }

    int numTilePossibilities(string tiles) {
        set<string> st;
        solve(tiles, st, "");
        return st.size();
    }
};