/*
*                                         Minimizing sums
*                             |a1 − x|^c + |a2 − x|^c + · · · + |an − x|^c.
*
*        Case 1. c == 1
*         |a1 − x| + |a2 − x| + · · · + |an − x|.
*         Greedy x -> median
*
*        Case 2. c == 2
*         (a1 − x)^2 + (a2 − x)^2 + · · · + (an − x)^2
*        == S(ai) + n*x - 2*x*(S(ai))
*         Greedy x -> average
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, C;cin >> N >> C;
    vector<int> A(N);for(int &i: A)cin >> i;

    if(C == 1){
       sort(A.begin(), A.end());
       int x = A[N/2]; // Median
       int ans = 0;
       for(int &i: A){
           ans += abs(i - x);
       }
       cout << ans << '\n';
    }
    else if (C == 2){
        int x = accumulate(A.begin(), A.end(), 0)/N; // Average
        int ans = 0;
        for(int &i: A){
            ans += (i-x)*(i-x);
        }
        cout << ans << '\n';
    }
    else{
        // Need more General Approch
    }

    return 0;
}