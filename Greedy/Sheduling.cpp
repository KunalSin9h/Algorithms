/*
*                                Sheduling Problems
*   The idea is to always select the next possible event that ends as early as
    possible
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    vector<array<int, 2>> d(N);
    for(int i = 0;i<N; ++i){
        cin >> d[i][0] >> d[i][1];
        //     ^start     ^end
    }
    // Greedy Strategy
    sort(d.begin(), d.end(), [&](array<int,2> a, array<int, 2> b)->bool{
        return a[1] < b[1];
    });

    int ans = 0;
    int curr = -1;
    for(int i = 0;i<N; ++i){
        if(d[i][0] < curr)continue;
        ans++;
        curr = d[i][1];
    }
    cout << ans << '\n';
    return 0;
}