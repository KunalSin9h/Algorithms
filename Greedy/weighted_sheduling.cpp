/*
 * Given N jobs where every job is represented by following three elements of it.

    1. Start Time
    2. Finish Time
    3. Profit or Value Associated (>= 0)

 * Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    vector<array<int, 3>> A(N);
    
    for(int i = 0;i<N; ++i){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
        //     ^start    ^end        ^profit
    }
    // Sort Jobs according to closer finish time
    sort(A.begin(), A.end(), [&](array<int, 3> p, array<int, 3> q)->bool{
        return p[1] < q[1];
    });

    /**
      *
      * Dp[i] -> value of optimal solution(profit) to the problem consisting of job requests 1, 2, ..., i.
      * P[i] -> best Previous job that is not conflicting
     **/

    // Bottom-Up Dynamic Programming
    vector<int> dp(N+1);
    dp[0] = 0; // No job No Profit

    vector<int> P(N+1);
    P[0] = 0; // No-Job so no Previous Best job
    P[1] = 0; // There is no Previous Best job for the first job (Haaa..)
    for(int i = 2; i<=N; ++i){
        int x = A[i-1][0];
        int l = -1, h = i-1;
        while(l < h){
            int md = l + ((h-l+1)>>1);
            if(A[md][1] > x)h = md - 1;
            else l = md;
        }
        l++;
        P[i] = l;
    }
    for(int i = 1;i<=N; ++i){
        dp[i] = max(dp[i-1], A[i-1][2] + dp[P[i]]);
        
    }
    cout << dp[N] << '\n';
    return 0;
}