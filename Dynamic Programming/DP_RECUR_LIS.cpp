#include <bits/stdc++.h>
using namespace std;

vector<int> arr, memo;

// Top-Down DP -> mainly top down are recursive  / But can be iterative also

/*
* Find The length of the longest subseq formed by element of given position 
* ONLY BRUT-FORCE
*/
int F(int pos){
	if(memo[pos] != -1)return memo[pos];
	for(int i = pos-1; i>=0; --i){
		if(arr[i] < arr[pos]){
			return memo[pos] = 1 + F(i);
		}
	}
	return memo[pos] = 1; //What is not less element in the array
}

int main(){
	int n; cin >> n;
	arr.resize(n);
	memo.resize(n, -1);
	memo[0] = 1;
	for(int i = 0;i<n; ++i)cin >> arr[i];
	int ans = 1;

	for(int i = 0; i<n; ++i){
		ans = max(ans, F(i));
	}
	cout << ans << "\n";
	return 0;
}