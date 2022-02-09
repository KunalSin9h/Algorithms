#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    vector<int> c(N), p(N);
    for(int &i: c)cin >> i;
    for(int &i: p)cin >> i;

    vector<vector<int>> dp(N+1, vector<int>(X+1));

    for(int i = 1;i<=N; ++i){
        for(int j = 1;j<=X; ++j){
            if(c[i-1] <= j) 
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - c[i-1]] + p[i-1]);
            else dp[i][j] = dp[i-1][j];
        }
    } 
    cout << dp[N][X] << '\n';
    return 0;
}