#include "bits/stdc++.h"
using namespace std;
void setio(std::string filename = ""){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

template<typename T>
inline void ckmax(T &a, T b){a = (a < b ? b : a);}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    setio("diamond");

    int N, K;cin >> N >> K;
    vector<int> A(N);for(int &i: A)cin >> i;
    sort(A.begin(), A.end());

    vector<int> p(N), mx(N);

    for(int i = 0, j = 0; j < N; ++j){
        while(i < N && A[j] - A[i] > K)i++;
        p[j] = i;
        mx[j] = j - i + 1;
    }

    for(int i = 1; i < N; ++i){
        ckmax(mx[i], mx[i-1]);
    }
    int ans = 0;

    for(int i = 0; i < N; ++i){
        ans = max(ans, (p[i] == 0 ? 0 : mx[p[i]-1]) + i - p[i] + 1);
    } 
    cout << ans << '\n';

    return 0;
}