#include <bits/stdc++.h>
using namespace std;

// A[i] + A[j] >= X;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, S;cin >> N >> S;
    vector<int> A(N);for(int &a: A)cin >> a;
    sort(A.begin(), A.end());

    int ans = 0;

    for(int i = 0, j = N - 1; i < j; --j){
        while(i < j && A[i] + A[j] < S)i++;
        if(A[i] + A[j] >= S){
            ans += j-i;
        }
    }
    cout << ans << '\n';

    return 0;
}