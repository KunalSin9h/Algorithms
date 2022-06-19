#include <bits/stdc++.h>
using namespace std;

/*
* Bottom-Up  DP
* dp[i][j] -> is it possible to make sum 'j' with element till 'i'
*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    vector<int> v(N);
    for(int &i: v)cin >> i;

    vector<vector<bool>> dp(N+1, vector<bool>(X+1));

    for(int i = 0;i<=N; ++i){
        dp[i][0] = true;
    }
    for(int i = 1;i<=N; ++i){
        for(int j = 1;j<=X; ++j){
            dp[i][j] = dp[i-1][j];
            if(j >= v[i-1]) // v[i-1] bcoz i is 1 based
                dp[i][j] = dp[i][j] | dp[i-1][j - v[i-1]];
        }
    }
    cout << (dp[N][X]?"True":"False") << '\n';
	return 0;
}
/*
* Time -> O(N*X)
*/