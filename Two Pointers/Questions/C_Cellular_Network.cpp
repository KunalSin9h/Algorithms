#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;cin >> N >> M;
    vector<int> C(N);for(int &c: C)cin >> c;
    vector<int> T(M);for(int &t: T)cin >> t;

    int ans = 0;    

    for(int i = 0, j = 0; i < N; ++i){
        while(j < M && T[j] < C[i])j++;
        int temp = 2e9;
        if(j < M){
            temp = min(temp, T[j] - C[i]);
        }
        if(j > 0){
            temp = min(temp, C[i] - T[j-1]);
        }
        ans = max(ans, temp);
    }
    cout << ans << '\n';
    return 0;
}