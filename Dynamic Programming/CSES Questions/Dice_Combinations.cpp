#include <bits/stdc++.h>
using namespace std;

constexpr int mod = int(1e9) + 7;

vector<int64_t> memo;

int64_t dfs(int64_t sum){
    assert(sum >= 0);
    if(sum == 0)return 1;
    if(memo[sum] != -1)return memo[sum];
    int64_t ways = 0;
    for(int64_t i = 1;i<=6; ++i){
        if(sum - i >= 0)
            ways += dfs(sum - i)%mod;
    }
    return memo[sum] = ways%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int64_t N;cin >> N;
    memo.resize(N + 10, -1);
    cout << dfs(N)%mod << '\n';
    return 0;
}