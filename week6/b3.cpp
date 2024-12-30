#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits> 
#include <algorithm>

using namespace std;

struct Edge {
    int to, capacity, flow;
    Edge* rev;
};

vector<Edge*> graph[10005];
int level[10005];
int ptr[10005];

void add_edge(int u, int v, int capacity) {
    Edge* uv = new Edge{v, capacity, 0, nullptr};
    Edge* vu = new Edge{u, 0, 0, uv};
    uv->rev = vu;
    graph[u].push_back(uv);
    graph[v].push_back(vu);
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto& edge : graph[u]) {
            if (level[edge->to] == -1 && edge->capacity > edge->flow) {
                level[edge->to] = level[u] + 1;
                if (edge->to == t) return true;
                q.push(edge->to);
            }
        }
    }
    return false;
}

int dfs(int u, int t, int flow) {
    if (u == t) return flow;
    for (; ptr[u] < graph[u].size(); ++ptr[u]) {
        Edge* edge = graph[u][ptr[u]];
        if (level[edge->to] == level[u] + 1 && edge->capacity > edge->flow) {
            int cur_flow = min(flow, edge->capacity - edge->flow);
            int pushed = dfs(edge->to, t, cur_flow);
            if (pushed > 0) {
                edge->flow += pushed;
                edge->rev->flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int edmonds_karp(int s, int t) {
    int max_flow = 0;

    while (bfs(s, t)) {
        memset(ptr, 0, sizeof(ptr));
        while (int flow = dfs(s, t, INT_MAX)) {
            max_flow += flow;
        }
    }

    return max_flow;
}

int main() {
    int N, M;
    cin >> N >> M;

    int s, t;
    cin >> s >> t;

    for (int i = 0; i < M; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        add_edge(u, v, cap);
    }

    int result = edmonds_karp(s, t);

    cout << result << endl;

    return 0;
}

