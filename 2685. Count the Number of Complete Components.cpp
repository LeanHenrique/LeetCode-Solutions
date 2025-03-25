class Solution {
public:
    void dfs(int i, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& component){
        visited[i] = true;
        component.push_back(i);

        for(int neighbor : adjList[i]) { 
            if(!visited[neighbor]) {
                dfs(neighbor, adjList, visited, component);
            }
        }
    }

    vector<vector<int>> ConnectedComponents(int n, vector<vector<int>>& edges, vector<vector<int>>& adjList){
        // Criando lista de adjacência
        adjList.resize(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]); // Grafo não direcionado
        }

        vector<bool> visited(n, false);
        vector<vector<int>> Components;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i, adjList, visited, component);
                Components.push_back(component);
            }
        }
        return Components;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList; // Criando lista de adjacência
        vector<vector<int>> components = ConnectedComponents(n, edges, adjList);
        int CompleteComponents = 0;

        for(const vector<int>& component : components){
            if (component.empty()) continue;

            int expectedDegree = component.size() - 1; 
            bool isComplete = true;

            for(int node : component){
                if(adjList[node].size() != expectedDegree){
                    isComplete = false;
                    break;
                }
            }
            if(isComplete){
                CompleteComponents++;
            }
        }
        return CompleteComponents;
    }
};
