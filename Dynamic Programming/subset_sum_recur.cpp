#include <bits/stdc++.h>
using namespace std;

int N, X;
vector<int> v;

int memo[205][20005];

bool dfs(int ind, int val){
    if(val == 0) return true;
    if(ind == N) return false;
    if(memo[ind][val] != -1) return memo[ind][val];
    bool possible = dfs(ind + 1, val);
    if(val >= v[ind])
        possible |= dfs(ind + 1, val - v[ind]);
    return memo[ind][val] = possible;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    memset(memo, -1, sizeof(memo));
    cin >> N >> X;
    v.resize(N);
    for(int &i: v)cin >> i;
    cout << (dfs(0, X)?"True":"False") << '\n';
	return 0;
}

