#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n,m;
vector<int> v;
vector<vector<int>> adj(100000 + 1, v);
vector<int> topo;
bool visited[100000 + 1];
int d[100000 + 1];
void dfs(int node) {
    visited[node] = true;

    for (auto u : adj[node] ) {
        if (!visited[u]) dfs(u);
    }
    topo.push_back(node);
}
int main() {
    for (int i = 0; i <=100000;i++) {
        visited[i] = false;
        d[i] = 0;
    }
    cin >> n >> m;
    while (m -- ){
        int left,right;
        cin >> left >> right;
        adj[left].push_back(right);
    }

    for (int i = 1; i <= n; i++) {
        if(!visited[i]) dfs(i);
    }
    int result = 0;
    for (int i = topo.size() - 1; i >=0 ;i--) {
        int current = topo[i];

        for (auto u :adj[current]) {
            if (d[u] > d[current] - 1) {
                d[u] = d[current] - 1;
                result = max(result, -d[u]);
            }
        }
    }

    cout << result << endl;

    return 0;
}

// Since its a DAG
// Topologically sort it
// Then relax edges from nodes considered in topo order. 
// Distance between each node is -1
// Return the maximum