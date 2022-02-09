#include <bits/stdc++.h>
using namespace std;

vector<int> f(int n){
    vector<int> res;
    while(n){
        res.push_back(n%10);
        n /= 10;
    }
    return res;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    vector<int> dp(N+1);
    dp[0] = 0;
    for(int i = 1;i<=N; ++i){
        auto dig = f(i);
        dp[i] = int(2e9);  
        for(int &j: dig){
            if(i - j >= 0)
                dp[i] = min(dp[i], dp[i-j] + 1);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}
/*
* Time -> O(N*logn)
*/ 