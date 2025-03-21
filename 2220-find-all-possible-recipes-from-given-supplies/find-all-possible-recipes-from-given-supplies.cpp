class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) 
    {
        unordered_map<string, vector<string>> adj;  // ingredient -> list of recipes that depend on it
        unordered_map<string, int> indegree;        // recipe -> number of missing ingredients
    unordered_set<string> supplySet(supplies.begin(), supplies.end());
    queue<string> q;
    vector<string> result;

    // Initialize indegree map
    for (int i = 0; i < recipes.size(); ++i) {
        indegree[recipes[i]] = ingredients[i].size();
        for (const string& ing : ingredients[i]) {
            adj[ing].push_back(recipes[i]);  // ingredient used by this recipe
        }
    }

    // Push initial supplies to queue
    for (const string& s : supplies) {
        q.push(s);
    }

    // Process the queue
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const string& dependentRecipe : adj[current]) {
            indegree[dependentRecipe]--;
            if (indegree[dependentRecipe] == 0) {  // All ingredients are ready
                q.push(dependentRecipe);
                result.push_back(dependentRecipe);
            }
        }
    }

    return result;
    }
};