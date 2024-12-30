//C++ 
#include <bits/stdc++.h> 


using namespace std;

bool hasHamiltonianCycle(int n, const vector<vector<int>>& adj) {
    vector<int> path;
    vector<bool> visited(n + 1, false);

    function<bool(int, int)> dfs = [&](int node, int count) {
        visited[node] = true;
        path.push_back(node);
        
        if (count == n) { // Check if a Hamiltonian cycle is found
            for (int neighbor : adj[node]) {
                if (neighbor == path[0]) {
                    return true; // Cycle back to the start
                }
            }
            visited[node] = false;
            path.pop_back();
            return false;
        }
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, count + 1)) {
                    return true;
                }
            }
        }
        
        visited[node] = false;
        path.pop_back();
        return false;
    };

    for (int i = 1; i <= n; ++i) { 
        if (dfs(i, 1)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        cout << (hasHamiltonianCycle(n, adj) ? 1 : 0) << endl;
    }
    return 0;
}

