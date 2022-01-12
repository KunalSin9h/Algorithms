#include <bits/stdc++.h>
using namespace std;

int fast(N, )
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);

	for(int i = 2;i<N; ++i){
		dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
	}

	cout << dp[N-1] << '\n';

	return 0;
}

