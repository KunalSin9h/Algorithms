#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
* top-down dp
* time -> o(2^n) -> o(n) :::: power of memeoization
*/
vector<int> dp;
int fib_top_down(int N){
    if(dp[N] != -1){
        return dp[N];
    }
    if(N < 2){
        dp[N] = N;
        return dp[N];
    }
    else return dp[N] = fib_top_down(N-1) + fib_top_down(N-2);
}

/* 
* Bottom-Up DP
*/
int fib_bottom_up(int N){
    if(N == 1)return 1;
    int prev = 0;
    int curr = 1;
    int next;
    for(int i = 2;i<=N; ++i){
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return next;
}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int main(){
    int P;cin >> P;
    int pp = P;
    int tc = 1;
    while(P--){
        int N = rng()%21 + 1;
        cout << N << '\n';
        dp.resize(N+1, -1);
        int a1 = fib_top_down(N);
        int a2 = fib_bottom_up(N);
        if(a1 != a2){
            cout << "Failed #" << tc << '\n';
            break;
        }else{
            cout << "Passed #" << tc << '\n';
            tc++;
        }
        dp.clear();
    }
    cout << "\nTest " << (P > 0? "Fails\n":"Passed\n") << '\n';
    return 0;
}
/*
*  Dp -> Brutforce Recursion + Memoization (not always)
*/