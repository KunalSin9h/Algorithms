#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    vector<int> c(N);for(int &i: c)cin >> i;

    vector<vector<int64_t>> dp(N+1, vector<int64_t>(X+1, 0));

    dp[0][0] = 1;

    for(int i = 1;i<=N; ++i){
        for(int j = 0;j<=X; ++j){
            dp[i][j] = dp[i-1][j]; // i will note use it 
            int left = j - c[i-1];
            if(left >= 0){
                dp[i][j] += dp[i][left]; // i have to use only i'th coin 
            }
        }
    }
    cout << dp[N][X] << '\n';
    return 0;
}