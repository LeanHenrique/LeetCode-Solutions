class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> TopologicGraph;
        unordered_map<string, int> dependences;
        unordered_set<string> supplySet(supplies.begin(), supplies.end());
        queue<string> q;
        vector<string> possibleRecipes;

        // Criando o grafo e contando dependências
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            dependences[recipe] = 0;

            for (const string& ingredient : ingredients[i]) {
                if (supplySet.find(ingredient) == supplySet.end()) { // Se o ingrediente não está disponível
                    TopologicGraph[ingredient].push_back(recipe);
                    dependences[recipe]++;
                }
            }

            // Se não tem dependências, já pode ser feito
            if (dependences[recipe] == 0) {
                q.push(recipe);
            }
        }

        // Processamento topológico (Kahn’s Algorithm)
        while (!q.empty()) {
            string recipe = q.front();
            q.pop();
            possibleRecipes.push_back(recipe);

            for (const string& nextRecipe : TopologicGraph[recipe]) {
                dependences[nextRecipe]--;
                if (dependences[nextRecipe] == 0) {
                    q.push(nextRecipe);
                }
            }
        }

        return possibleRecipes;
    }
};
