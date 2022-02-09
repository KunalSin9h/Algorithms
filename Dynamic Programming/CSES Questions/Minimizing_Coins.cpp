#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;cin >> N >> X;
    vector<int> coins(N);for(int &i: coins)cin >> i;

    vector<int64_t> dp(X+1, 2e9);
    dp[0] = 0;
    for(int i = 1;i<=X;++i){
        for(int j = 0;j<N; ++j){
            if(i >= coins[j])
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    if(dp[X] == 2e9)cout << -1 << '\n';
    else cout << dp[X] << '\n';
    return 0;
}