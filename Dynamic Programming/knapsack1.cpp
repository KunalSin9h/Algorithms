#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Problem Statement
There are
N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wi and a value of vi.
Taro has decided to choose some of the N items and carry them home in a knapsack. The capacity of the knapsack is W, 
which means that the sum of the weights of items taken must be at most W.
Find the maximum possible sum of the values of items that Taro takes home.
*/


int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, W;
    cin >> N >> W;

	vector<array<int, 2>> a(N+1);
	int w, v;
	for(int i = 1;i<=N; ++i){
		cin >> w >> v;
		a[i][0] = w;
		a[i][1] = v;
	}
	
	vector<vector<int64_t>> dp(N+1, vector<int64_t>(W+1));
	
	for(int i = 1;i<=N; ++i){
		for(int j = 1;j<=W; ++j){
			if(a[i][0] <= j){
				dp[i][j] = max(dp[i-1][j] , a[i][1] + dp[i-1][j-a[i][0]]);
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[N][W] << '\n';	
    return 0;
}
/*
* Time -> O(N*W)
*/
