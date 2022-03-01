#include <bits/stdc++.h>
using namespace std;

/*

Breadth-first search

Breadth first search is one of the basic and essential searching algorithms on graphs.

Applications of BFS

    1. find the shortest path from a source to other vertices in an unweighted graph.
    time -> o(n + m)
    n -> number of vertex
    m -> number of Edges

*/

int main(){
    /*
    int argc, char * argv[]
    if(argc > 1){
        string s = argv[1];
        freopen(s.c_str(), "r", stdin);
    }
    */
    cin.tie(0)->sync_with_stdio(0);
    int V, E;
    cin >> V >> E;

    vector<int> graph[V];
    int x, y;
    while(E--){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // Find the shotest path for every node from source in un-weighted graphs

    vector<int> dist(V);
    vector<bool> vis(V, false);
    vector<int> parent(V);
    parent[0] = -1;
    vis[0] = true;
    queue<int> bfs;

    bfs.push(0); // Source Vertex {important}
    
    while(!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        vis[node] = true;
        for(int &c: graph[node]){
            if(vis[c])continue;
            dist[c] = dist[node] + 1;
            parent[c] = node;
            bfs.push(c);
        }
    }
    int t;
    cin >> t;
    cout << "Shotest Path from 0 -> " << dist[t] << '\n';
    cout << "Path:" << '\n';
    for(int i = t;i != -1; i = parent[i]) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}