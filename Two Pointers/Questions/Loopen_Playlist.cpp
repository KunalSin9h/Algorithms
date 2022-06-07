#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;cin >> N;
    int64_t P;cin >> P;

    vector<int> A((N<<1));
    
    int64_t sum = 0; 

    for(int i = 0; i < N; ++i){
        cin >> A[i];
        sum += A[i];
        A[i+N] = A[i];
    }
    
    int64_t a = 0;
    if(sum < P){

        a = (P/sum)*N;

        P %= sum;
        
    }

    if(P == 0){
        cout << 1 << ' ' << a << '\n';
        exit(0);
    }

    int idx = 0;
    int len = INT_MAX;
    int64_t new_sum = 0;

    for(int i = 0, j = 0; j < (N<<1); ++j){
        new_sum += A[j];
        while(i < (N<<1) && (new_sum - A[i]) >= P){
            new_sum -= A[i];
            i++;
        }
        if(new_sum >= P){
            int tlen = j - i + 1;
            if(len > tlen){
                len = tlen;
                idx = i;
            }
        }
    }

    assert(len < N); 
    assert(idx < N); 

    cout << idx + 1 << ' ' << a + len << '\n';
    
    return 0;
}
