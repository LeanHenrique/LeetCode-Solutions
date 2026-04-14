class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto courseadj : prerequisites){
            adj[courseadj[1]].push_back(courseadj[0]);
        }

        vector<bool> inStack(numCourses);
        vector<bool> visited(numCourses);

        for(int i = 0; i < numCourses; i++){
            if(dfs(i, adj, inStack, visited))return false;
        }

        return true;
    }

    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& inStack, vector<bool>& visited){
        
        if(inStack[node])return true;

        if(visited[node])return false;

        inStack[node] = true;
        visited[node] = true;

        for(auto neighbor : adj[node]){
            if(dfs(neighbor, adj, inStack, visited)) return true;
        }

        inStack[node] = false;
        return false;
    }
};
