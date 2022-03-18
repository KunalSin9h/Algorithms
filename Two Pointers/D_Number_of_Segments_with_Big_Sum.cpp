#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;cin >> N;
    int64_t S;cin >> S;
    vector<int> A(N);for(int &a: A)cin >> a;


    int64_t sum = 0;
    int64_t ans = 0;

    for(int i = 0, j = 0; j < N; ++j){
        sum += A[j];
        while(sum - A[i] >= S){
            sum -= A[i];
            i++;
        }
        if(sum >= S){
            ans += i + 1;
        }
    }
    std::cout << ans << '\n';
    return 0;
}
