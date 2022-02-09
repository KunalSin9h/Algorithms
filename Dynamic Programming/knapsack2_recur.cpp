#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> a;

constexpr int64_t inf = 1e18;
int64_t memo[105][int(1e5) + 5];

int64_t dfs(int ind, int val){
    if(val == 0)return 0;
    if(ind <= 0)return inf;
    if(memo[ind][val] != -1)return memo[ind][val];
    int64_t ans = dfs(ind-1, val);

    if(val - a[ind][1] >= 0)
        ans = min(ans, dfs(ind-1, val - a[ind][1]) + a[ind][0]);
    return memo[ind][val] = ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    int N, W;cin >> N >> W;
    a.resize(N+1); 
    for(int i = 1;i<=N; ++i){
        cin >> a[i][0] >> a[i][1];
    }

    int ans = int(1e5);
    for(int i = ans;i>=0; --i){
        if(dfs(N, i) <= W){
            cout << i << '\n';
            exit(0);
        }
    }
    return 0;
}