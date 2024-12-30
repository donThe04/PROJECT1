#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int dijkstra(int n, const vector<vector<pii>>& adj, int s, int t) {
    vector<int> dist(n + 1, INT_MAX); 
    dist[s] = 0; 
    priority_queue<pii, vector<pii>, greater<pii>> pq; 
    pq.push({0, s}); 
    while (!pq.empty()) {
        int d = pq.top().first; 
        int u = pq.top().second; 
        pq.pop();

        if (d > dist[u]) continue;

        if (u == t) return dist[u];

        for (auto& edge : adj[u]) {
            int v = edge.first; 
            int w = edge.second; 

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1); 

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); 
    }

    int s, t;
    cin >> s >> t;

    int result = dijkstra(n, adj, s, t);

    cout << result << endl;

    return 0;
}

