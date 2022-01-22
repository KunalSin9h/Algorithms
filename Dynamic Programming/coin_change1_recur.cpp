#include <bits/stdc++.h>
using namespace std;

int d, a;
vector<int> coins, memo;

/*
* Choose minimum number of denominations to represents the total amount
*/

// Recursion -> through Top-down approach

int dfs(int amount){
	if(memo[amount] !=  -1)return memo[amount];
	int ans = INT_MAX;
	for(int &i: coins){
		if(i <= amount)
			ans = min(ans, dfs(amount - i) + 1);
	}
	return memo[amount] = ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> d >> a;
    coins.resize(d);
	memo.resize(a+1, -1);
	memo[0] = 0;
    for(int &i: coins)cin >> i;
	int ans = dfs(a);

	cout << (ans==INT_MAX?-1:ans) << '\n';

    return 0;
}
