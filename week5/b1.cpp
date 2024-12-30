#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[node] = true;
    result.push_back(node);
    
    // Traverse neighbors in sorted (lexicographic) order
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, result);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
 
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<bool> visited(n + 1, false);
    vector<int> result;
   
    dfs(1, adj, visited, result);
    
    
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

