#include <bits/stdc++.h>
using namespace std;
/*
* You are given strings s and t. Find one longest string that is a subsequence of both s and t.
*
*   SUBSEQUENCE -
*   A subsequence of a string x is the string obtained by removing zero or more characters from x 
    and concatenating the remaining characters without changing the order
*/

/* ITERATIVE */

int main(){
    string S, T;
    cin >> S >> T;

	int a = S.size();
	int b = T.size();
	
	vector<vector<int>> dp(a+1, vector<int>(b+1));
	
	for(int i = 0;i<=a; ++i){
		for(int j = 0;j<=b; ++j){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
				continue;
			}
			if(S[i-1] == T[j-1]){
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[a][b] << '\n';
	/*
    string ans;
	int i = a, j = b;	
	while(i > 0 && j > 0){
		if(S[i-1] == T[j-1]){
			ans.push_back(S[i-1]);
			i = i - 1;j = j - 1;
		}
		else{
			if(dp[i-1][j] >= dp[i][j-1]){
				i = i -1;
			}
			else{
				j = j -1;
			}
		}
	}
	int dig = ans.size();
	for(int i = dig -1;i>=0; --i){
		cout << ans[i];
	}
	cout << '\n';
	*/
    return 0;
}
