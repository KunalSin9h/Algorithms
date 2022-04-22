#include "bits/stdc++.h"
using namespace std;
void setio(std::string filename = ""){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
//    setio("pairup");
    int N;cin >> N;
    vector<array<int, 2>> A(N);
    for(int i = 0; i < N; ++i)cin >> A[i][1] >> A[i][0];
    sort(A.begin(), A.end());
    int ans = 0;
    int i = 0, j = N - 1;
    while(i < j){
        if(A[i][1] == 0)i++;
        if(A[j][1] == 0)j--;
        ans = max(ans, A[i][0] + A[j][0]);
        A[i][1]--;
        A[j][1]--;
    }
    cout << ans << '\n';
    return 0;
}