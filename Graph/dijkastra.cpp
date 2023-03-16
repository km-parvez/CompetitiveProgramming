#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17; // A very large number to represent infinity

vector<pair<int, int>> adj[100005]; // adjacency list to represent the graph
vector<long long> dist(100005, INF); // initialize distances to infinity
vector<int> previous(100005, -1); // initialize previous nodes to -1
    
int n, m; // number of vertices and edges

void dijkstra(int s) {
    dist[s] = 0; // distance to starting vertex is 0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s}); // push the starting vertex with a distance of 0
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) { // if we found a shorter path
                dist[v] = dist[u] + w; // update the distance
                previous[v] = u; // set the previous node
                pq.push({dist[v], v}); // add the vertex to the priority queue
            }
        }
    }
   
}
vector<int> getPath(int to){
    if (dist[to] == INF) { // if there is no path from 1 to n
        return {-1};
    } else {
        vector<int> path;
        int cur = to;
        while (cur != -1) { // construct the path from n to 1
            path.push_back(cur);
            cur = previous[cur];
        }
        reverse(path.begin(), path.end()); // reverse the path to get it from 1 to n
        return path;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // add edges to both vertices since the graph is undirected
    }
    dijkstra(1); // single source that is from 1
    vector<int> path = getPath(n);
    if (path[0] == -1) { // if there is no path from 1 to n
        cout << "-1" << endl;
    } else {
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
