#include <bits/stdc++.h>
using namespace std;

constexpr int mod = int(1e9) + 7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
	// dp[i][v] = number of ways to fill the array up to index i, if x[i] = v.

	using num = modnum<int(1e9)+7>;
	vector<vector<num>> dp(N, vector<num>(M+1, 0));

	int x0;cin >> x0;
	if(x0 == 0){
		fill(dp[0].begin(), dp[0].end(), 1);
	}else dp[0][x0] = 1;
	int x;
	for(int i = 1;i<N; ++i){
		cin >> x;
		if(x == 0){
			for(int j = 1;j<=M; ++j){
				for(const int &k: {j-1, j, j+1}){
					if(k >= 1 && k <= M){
						(dp[i][j] += dp[i-1][k]) %= mod;
					}
				}
			}
		}else{
			for(const int &k: {x-1, x, x+1}){
				if(k >= 1 && k<=M){
					(dp[i][x] += dp[i-1][k]) %= mod;
				}
			}
		}
	}
	num ans = 0;
	for(int i = 1;i<=M; ++i){
		(ans += dp[N-1][i]) %= mod;
	}
	cout << ans << '\n';	
    return 0;
}
