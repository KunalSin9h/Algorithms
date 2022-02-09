#include <bits/stdc++.h>
using namespace std;

vector<array<int, 2>> a;

int64_t memo[105][100005];

int64_t dfs(int ind, int weight){
    if(ind == 0 || weight == 0){
        return 0;
    }
    if(memo[ind][weight] != -1)return memo[ind][weight];
    int64_t ans = 0;
    if(weight >= a[ind][0])
        ans =  a[ind][1] + dfs(ind - 1, weight - a[ind][0]);
    
    ans = max(ans, dfs(ind - 1, weight));
    return memo[ind][weight] = ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    int N, W;
    cin >> N >> W;
    a.resize(N + 1);
    for(int i = 1;i<=N; ++i){
        cin >> a[i][0] >> a[i][1];
    }
    cout << dfs(N, W) << '\n';
    return 0;
}
