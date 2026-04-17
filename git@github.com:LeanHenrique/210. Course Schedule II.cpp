class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> inStack(numCourses);
        vector<bool> visited(numCourses);
        vector<int> result;
        int node = 0;

        for(auto requisite : prerequisites){
            adj[requisite[1]].push_back(requisite[0]);
        }

        for(int i = 0; i < numCourses; i++){
            int node = i;
            if(!verifyCicle(node, adj, inStack, visited, result)) return {};
        }

        reverse(result.begin(), result.end());

        return result;
    }

    bool verifyCicle(int node, vector<vector<int>>& adj, vector<bool>& inStack, vector<bool>& visited, vector<int>& result){
        if(inStack[node])return false;
        if(visited[node])return true;

        inStack[node] = true;
        visited[node] = true;

        for(auto neighbor : adj[node]){
            if(!verifyCicle(neighbor, adj, inStack, visited, result)) return false;
        }

        result.push_back(node);
        inStack[node] = false;
        return true;
    }

};
