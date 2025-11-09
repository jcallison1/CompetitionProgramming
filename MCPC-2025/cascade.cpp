#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int, int>

#define DEBUG 1

int ko;

// int degree(vector<vector<int>>& graph int node) {
//     int h = 0;

//     for (int i : graph[node]) {
//         if (i != ko) h++;
//     }

//     return h;
// }

double dfs(vector<vector<int>>& graph, vector<bool>& hit, int source, double degree_product) {
    double g = 0.0;

    if (source != ko) g += 1.0 / (degree_product * graph[source].size());

    for (int other_vert : graph[source]) {
        if (hit[other_vert]) continue;

        hit[other_vert] = true;

        g += dfs(graph, hit, other_vert, source == ko ? degree_product : degree_product * graph[source].size());

        hit[other_vert] = false;
    }

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int vertexes, edges;
    cin >> vertexes >> edges;

    // if (vertexes == 1) {
    //     cout << 1 << endl;
    //     return 0;
    // }

    vector<vector<int>> graph(vertexes, vector<int>());

    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cin >> ko;
    ko--;

    int source = ko;

    double sum = 1.0;

    // for (int source = 0; source < vertexes; source++) {
    //     if (source == ko) continue;

        vector<bool> hit(vertexes, false);

        hit[source] = true;

        sum += dfs(graph, hit, source, 1.0);
    // }

    cout << fixed << setprecision(1) << sum << endl;

    return 0;
}