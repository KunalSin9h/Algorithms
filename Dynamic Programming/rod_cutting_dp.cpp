#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int L, M;cin >> L >> M;
    vector<array<int, 2>> g(M);
    for(int i = 0;i<M; ++i){
        cin >> g[i][0] >> g[i][1];
    }


    vector<int> dp(L+1);
    dp[0] = 0; // price to cut a rod of 0 length
    for(int i = 1;i<=L; ++i){
        for(int j = 0;j<M; ++j){
            if(i >= g[j][0]){
                dp[i] = max(dp[i], dp[i-g[j][0]] + g[j][1]);
            }
        }
    }
    cout << dp[L] << '\n';
    return 0;
}
/*
* time -> O(L*M)
*/ 