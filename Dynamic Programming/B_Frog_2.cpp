#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> h, memo;
int K;

ll dp(ll M){
    if(memo[M] != -1)return memo[M];
    if(M <= 0)return 0;

    ll mxc = 2e9;
    for(int q = 1;q<=K; ++q){
        if(M-q >= 0)
            mxc = min(mxc, (dp(M-q) + abs(h[M] - h[M-q]))); 
    }
    return memo[M] = mxc;
}

int main(){
    ll N;cin >> N >> K;
    h.resize(N);memo.resize(N, -1);
    for(ll &i: h)cin >> i;
    N--;
    cout << dp(N) << '\n';
    return 0;
}
/*
* Time -> O(2^n)
* After memorization -> O(n)
*/