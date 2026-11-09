class Solution {
public:

    bool dfs(int node, stack<int>& st,vector<int>& visited,vector<int>& pathvisited,vector<vector<int>>& adj){
        visited[node] = 1;
        pathvisited[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(dfs(it, st, visited, pathvisited, adj)) {
                    return true;
                }
            }
            else if(pathvisited[it]) {
                return true;
            }
        }
        pathvisited[node] = 0;
        st.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses,vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        stack<int> st;
        vector<int> visited(numCourses, 0);
        vector<int> pathvisited(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) {
                if(dfs(i, st, visited, pathvisited, adj)) {
                    return {};
                }
            }
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};