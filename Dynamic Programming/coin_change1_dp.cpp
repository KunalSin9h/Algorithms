#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 2e9;

int main(){
    cin.tie(0)->sync_with_stdio(0);
	int d, a;
	cin >> d >> a;

	vector<int> coins(d);
	for(int &i: coins)cin >> i;
	// Bottom-Up dp
	vector<int64_t> dp(a+1, inf);

	dp[0] = 0;

	for(int i = 1;i<=a; ++i){
		for(int &j: coins){
			if(i >= j){
				dp[i] = min(dp[i], dp[i-j] + 1);
			}
		}
	}
	if(dp[a] == inf)cout << -1 << '\n';
	else cout << dp[a] << '\n';

    return 0;
}

