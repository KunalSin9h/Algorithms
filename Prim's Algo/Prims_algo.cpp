#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

int main(){
    int v, e;
    cin >> v >> e;
    vector<pi> graph[v];
    while(e--){
        int a, b, wt;
        cin >> a >> b >> wt;
        a--;b--; // Takeing Zero Based indexing
        graph[a].push_back({b, wt});
        graph[b].push_back({a, wt});
    }

    int parent[v];
    int visited[v];



    return 0;
}