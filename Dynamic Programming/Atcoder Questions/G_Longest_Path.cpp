#include <bits/stdc++.h>
using namespace std;

vector<int> dp;
vector<vector<int>> graph;
vector<int> degree;

void dfs(int node){
    for(int &child: graph[node]){
        dp[child] = max(dp[child], 1 + dp[node]);
        degree[child]--;
        if(degree[child] == 0)dfs(child);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;cin >> N >> M;
    dp.resize(N);
    degree.resize(N);
    graph.resize(N);
    int x, y;
    while(M--){
        cin >> x >> y;
        x--;y--;
        dp[y] =  -1;
        // x -> y
        graph[x].push_back(y);
        degree[y]++;
    }
    for(int i = 0;i<N; ++i){
        if(dp[i] == 0){
            dfs(i);
        }
    }
    cout << *max_element(dp.begin(), dp.end())  << '\n';
    return 0;
}