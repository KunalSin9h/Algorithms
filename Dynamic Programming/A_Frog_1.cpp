#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> h, memo;
int K;

ll dp(ll M){
    if(memo[M] != -1)return memo[M];
    if(M <= 0)return 0;
    return memo[M] =  min(
        (dp(M-1) + abs(h[M] - h[M-1])),
        (dp(M-2) + abs(h[M] - h[M-2]))
    );
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