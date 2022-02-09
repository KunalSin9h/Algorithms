#include <bits/stdc++.h>
using namespace std;

constexpr int mod = int(1e9) + 7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int64_t N;cin >> N;
    vector<int64_t> dp(N+1, 0);
    dp[0] = 1; // Nuber of ways to make sum = 0 is 1

    for(int i = 1;i<= N; ++i){
        for(int j = 1;j<=6; ++j){
            if(i >= j)
                dp[i] += dp[i-j]%mod;
            dp[i] %= mod;
        }
    }
    cout << dp[N] << '\n';
    return 0;
}