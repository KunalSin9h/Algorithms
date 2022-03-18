#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T;cin >> T;
	while(T--){
		int n;cin >> n;
		vector<int> a(n), dp(n);
		for(int &i: a)cin >> i;

		dp[0] = 1; 
		for(int i = 1;i<n; ++i){
			bool ch = false;
			for(int j = i-1; j>=0; --j){
				if(a[j] < a[i]){
					dp[i] = 1 + dp[j];
					ch = true;
					break;
				}
			}
			if(!ch)dp[i] = 1;
		}
		cout << *max_element(begin(dp), end(dp))  + 1<< '\n';
	}
    return 0;
}
