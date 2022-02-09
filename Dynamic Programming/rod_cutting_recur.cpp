#include <bits/stdc++.h>
using namespace std;

/*
* Unbounded - Knapsack 
* not Fractional - Knapsack
*/

int L;
int M;
vector<array<int, 2>> g;

/*
* Dfs -> return's the max price i can get when i have to cut a lenght of "len"
*/

int memo[100005];

int dfs(int len){
    if(len == 0)return 0;
    if(memo[len] != -1)return memo[len];
    int ans = 0;
    for(int i = 0;i<M; ++i){
        if(len >= g[i][0])
            ans = max(ans, dfs(len - g[i][0]) + g[i][1]);
    }
    return memo[len] = ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> L >> M;
    g.resize(M);
    fill(memo, memo + 100005, -1); //memset is slow
    for(int i = 0;i<M; ++i){
        cin >> g[i][0] >> g[i][1];
    }
    cout << dfs(L) << '\n';
    return 0;
}