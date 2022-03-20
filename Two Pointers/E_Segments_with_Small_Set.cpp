#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K;cin >> N >> K;
    vector<int> A(N);for(int &a: A)cin >> a;

    /**
     * Coordinate-Compression can be helpfull to counter the case of A[i] <= 1e9
     **/

    vector<int> cnt;

    {
        vector<int> temp = A;
        sort(temp.begin(), temp.end());
        temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
        cnt.resize(int(temp.size()), 0);
        for(int i = 0;i<N; ++i){
            A[i] = int(lower_bound(temp.begin(), temp.end(), A[i]) - temp.begin());
        }
    }

    int u = 0; // Number of Unique elements

    auto add = [&](int x)->void{
        cnt[x]++;
        u += cnt[x] == 1;        
    };

    auto remove = [&](int x)->void{
        cnt[x]--;
        u -= cnt[x] == 0;        
    };

    auto good = [&]()->bool{
        return u <= K;
    }; 

    int64_t ans = 0;

    for(int i = 0, j = 0; j < N; ++j){
        add(A[j]);
        while(!good()){
            remove(A[i]);
            i++;
        }
        if(u <= K){
            ans += j - i + 1;
        }
    } 
    cout << ans << '\n';
    return 0;
}
