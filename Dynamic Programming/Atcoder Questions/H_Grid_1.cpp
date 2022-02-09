#include <bits/stdc++.h>
using namespace std;

constexpr int mod = int(1e9) + 7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int H, W;
    cin >> H >> W;
    vector<vector<bool>> a(H+1, vector<bool>(W+1));
    char c;
    for(int i = 1;i<=H; ++i){
        for(int j = 1;j<=W; ++j){
            cin >> c;
            a[i][j] = (c=='.'?true:false);
        }
    }
    vector<vector<int64_t>> dp(H+1, vector<int64_t>(W+1));
    dp[1][1] = 1;
    for(int i = 1;i<=H; ++i){
        for(int j = 1;j<=W; ++j){
            if(i == 1 && j == 1)continue;
            if(a[i][j]){
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }else dp[i][j] = 0;
        }
    }
    cout << dp[H][W]%mod << '\n';
    return 0;
}