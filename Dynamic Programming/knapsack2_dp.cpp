#include <bits/stdc++.h>
using namespace std;

//rotation of DP state -> Depending upon the constraints

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, W;
	cin >> N >> W;
	int64_t max_val = 0;	

	vector<array<int, 2>> a(N+1);

	int w, v;
	for(int i = 1;i<=N; ++i){
		cin >> w >> v;
		a[i][0] = w;
		a[i][1] = v;
		max_val += v;
	}

	vector<vector<int64_t>> dp(N+1, vector<int64_t>(max_val + 1, 1e18));
	for(int i = 0;i<=N; ++i){
		dp[i][0] = 0;
	}
	for(int i = 1;i<=N; ++i){
		for(int j = 1;j<=max_val;++j){
			if(j >= a[i][1]){
				dp[i][j] = min(dp[i-1][j], a[i][0] + dp[i-1][j-a[i][1]]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	int ans = 0;
	for(int j = 1;j<=max_val; ++j){
		if(dp[N][j] <= W){
			ans = j;
		}
	}
	cout << ans << '\n';
    return 0;
}
