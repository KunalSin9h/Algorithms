#include <bits/stdc++.h>
using namespace std;

constexpr int mod = int(1e9) + 7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int64_t N, X;cin >> N >> X;
    vector<int64_t> c(N);for(int64_t &i: c)cin >> i;

    vector<int64_t> dp(X+1);
    dp[0] = 1;

    for(int i = 1;i<=X; ++i){
        for(int64_t &j: c){
            if(i >= j)
                dp[i] += dp[i-j]%mod;
            dp[i] %= mod;
        }
    }
    cout << dp[X]%mod << '\n';
    return 0;
}