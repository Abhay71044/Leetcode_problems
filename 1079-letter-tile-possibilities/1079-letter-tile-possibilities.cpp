class Solution {
public:

    void solve(string&tiles,set<string>&st, vector<bool>&visited,string&output){
        if(!output.empty()){
            st.insert(output);
        }
        for(int i=0;i<tiles.size();i++){
            if(visited[i]){
                continue;
            }
            visited[i]=true;
            output.push_back(tiles[i]);
            solve(tiles,st,visited,output);
            output.pop_back();
            visited[i]=false;
        }
    }

    int numTilePossibilities(string tiles) {
        set<string>st;
        vector<bool>visited(tiles.size(),false);
        string output="";
        solve(tiles,st,visited,output);
        return st.size();
    }
};