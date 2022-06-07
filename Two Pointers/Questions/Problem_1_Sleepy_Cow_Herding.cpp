#include "bits/stdc++.h"
using namespace std;
void setio(std::string filename = ""){
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    //setio("herding");
    int N;cin >> N;
    vector<int> A(N);for(int &i : A)cin >> i;
    sort(A.begin(), A.end());

    int64_t a = LLONG_MAX;

    if(((A[N-2] - A[0]) == N - 2) && ((A[N-1] - A[N-2] - 1) >= 2)){
        a = 2;
        goto ans;
    }

    if((((A[N-1] - A[1]) == N - 2)) && ((A[1] - A[0] - 1) >= 2)){
        a = 2;
        goto ans;
    }

    for(int i = 0, j = 0; i < N; ++i){
        while(j + 1 < N && A[j+1] - A[i] <= N - 1)j++;
        a = std::min<int64_t>(a, (N - (j - i + 1)));
    }

    ans:
        assert(a != LLONG_MAX);
        cout << a << '\n';
        cout << (A[N-1] - A[0] - 1 - (N-2)) - std::min((A[1] - A[0] - 1), (A[N-1] - A[N-2] - 1)) << '\n';

    return 0;
}