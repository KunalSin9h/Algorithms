#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M, S, A, B;
    cin >> N >> M >> S >> A >> B;

    vector<array<int, 2>> a(N), b(M);
    for(int i = 0; i < N; ++i){
        a[i][0] = A;
        cin >> a[i][1];
    }
    for(int i = 0; i < M; ++i){
        b[i][0] = B;
        cin >> b[i][1];
    }
    int64_t ans = 0, ww = 0, cc = 0; 

    if(A >= B){
        b.insert(b.end(), a.begin(), a.end());
        for(int i = 0, j = 0; j < (N + M); ++j){
            ww += b[j][0];
            cc += b[j][1];
            while(ww > S){
                ww -= b[i][0];
                cc -= b[i][1];
                i++;
            }
            ans = max(ans, cc);
        }
    }
    else{
        a.insert(a.end(), b.begin(), b.end());
        for(int i = 0, j = 0; j < (N + M); ++j){
            ww += a[j][0];
            cc += a[j][1];
            while(ww > S){
                ww -= b[i][0];
                cc -= b[i][1];
                i++;
            }
            ans = max(ans, cc);
        }
    }

    cout << ans << '\n';

    return 0;
}
