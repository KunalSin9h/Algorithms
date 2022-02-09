#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int64_t N, K, X;
    cin >> N >> K >> X;
	
	int mod = 1e9 + 7;

    vector<num> a(N), b(N);

    a[0] = X == 1;
    b[0] = X != 1;

    for(int i = 1;i<N; ++i){
        a[i] = b[i-1]%mod;
        b[i] = (a[i-1]*(K-1) + b[i-1]*(K-2))%mod;
    }
    cout << a[N-1] << '\n';
    return 0;
}
