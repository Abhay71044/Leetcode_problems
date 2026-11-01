class Solution {
public:

    bool check(int node,int v,vector<int>&color,vector<vector<int>>& graph){
        queue<int>q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:graph[curr]){
                if(color[it]==-1){
                    color[it]=!color[curr];
                    q.push(it);
                }
                else if(color[it]==color[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(check(i,v,color,graph)==false) return false;
            }
        }
        return true;
    }
};