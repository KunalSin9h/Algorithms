#include <bits/stdc++.h>
using namespace std;

constexpr int m = int(1e9) + 7;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    int M;cin >> M;
    vector<array<int, 3>> A(N);
    
    for(int i = 0;i<N; ++i){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
    sort(A.begin(), A.end(), [&](array<int, 3> p, array<int, 3> q)->bool{
        return p[1] < q[1];
    });

    vector<int> P(N+1);
    P[0] = 0;
    P[1] = 0; 
    for(int i = 2; i<=N; ++i){
        int x = A[i-1][0];
        int l = -1, h = i-1;
        while(l < h){
            int md = l + ((h-l+1)>>1);
            if(A[md][1] > x)h = md - 1;
            else l = md;
        }
        P[i] = ++l;
    }

    vector<array<int, 2>> dp(N+1);
    dp[0][0] = dp[0][1] = 0;

    for(int i = 1;i<=N; ++i){
        int a = dp[i-1][0];
        int b = A[i-1][2] + dp[P[i]][0];
        if(a >= b){
            dp[i][0] = a;
            dp[i][1] = dp[i-1][1];
        }
        else{
            dp[i][0] = b;
            dp[i][1] = (A[i-1][1] - A[i-1][0]) + dp[P[i]][1];
        }
    }
    cout << (dp[N][0]*1LL*dp[N][1])%m << '\n';
    return 0;
}