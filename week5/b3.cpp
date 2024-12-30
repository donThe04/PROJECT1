#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return false;
        }
 
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; 
        edges[i].v--;
    }


    sort(edges.begin(), edges.end());

    UnionFind uf(N);
    int mst_weight = 0;
    int edges_used = 0;

    for (const auto& edge : edges) {
        if (uf.unionSets(edge.u, edge.v)) {
            mst_weight += edge.weight;
            edges_used++;
            if (edges_used == N - 1) {
                break;
            }
        }
    }

    cout << mst_weight << endl;

    return 0;
}

