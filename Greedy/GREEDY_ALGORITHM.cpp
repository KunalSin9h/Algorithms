/*
*                                 GREEDY ALGORITHM
* Selecting the choice that seems to be the best at the moment at every step of your algorithm.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, S;
    cin >> N >> S;

    vector<int> C(N);for(int &i: C)cin >>i;
    sort(C.begin(), C.end(), greater<int>());

    int ans = 0;
    vector<int> used;
    for(int i = 0;i<N; ++i){
        if(S >= C[i]){
            int temp = S/C[i];
            ans += temp;
            S -= temp*C[i];
            while(temp--)used.push_back(C[i]);
        }
    }
    assert(S == 0);
    cout << ans << '\n';
    for(int &i: used)cout << i << " ";
    cout << '\n';
    return 0;
}