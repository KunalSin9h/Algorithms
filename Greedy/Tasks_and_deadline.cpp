/*
*                                  Tasks and Deadline
*   greedy strategy is to simply perform the tasks sorted by their durations in increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    vector<array<int, 2>> tasks(N);

    for(int i = 0;i<N; ++i){
        cin >> tasks[i][0] >> tasks[i][1];
            // ^Duration      ^Deadline
    }

    sort(tasks.begin(), tasks.end(), [&](array<int, 2> a, array<int, 2> b)->bool{
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });

    int ans = 0;
    int done = 0;
    for(int i = 0;i<N; ++i){
        done += tasks[i][0];
        ans += tasks[i][1] - done;
    }
    cout << ans << '\n';
    return 0;
}