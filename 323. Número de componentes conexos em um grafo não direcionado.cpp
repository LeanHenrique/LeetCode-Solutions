class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
       int components  = 0;
       vector<vector<int>> listAdj(n);
       vector<bool> visited(n);

       for(auto edge : edges){
        listAdj[edge[0]].push_back(edge[1]);
        listAdj[edge[1]].push_back(edge[0]);
       }

       for(int i = 0; i < n; i++){
        if(!visited[i]){
            components++;
            dfs(i, listAdj, visited);
        }
       }
       return components;
    }

    void dfs(int node, vector<vector<int>>& listAdj, vector<bool>& visited){
        if(visited[node]) return;

        visited[node] = true;

        for(auto neighbor : listAdj[node]){
            dfs(neighbor, listAdj, visited);
        }
    }
};
