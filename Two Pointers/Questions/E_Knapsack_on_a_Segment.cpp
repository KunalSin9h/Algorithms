#include "bits/stdc++.h"
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, X;cin >> N >> X;
    vector<array<int, 2>> A(N);

    for(int i : {0, 1}){
        for(int j = 0 ;j < N; ++j){
            cin >> A[j][i];
        }
    }

    int64_t sum = 0;
    int64_t cost = 0;
    int64_t best_cost = 0;

    for(int i = 0, j = 0; j < N; ++j){
        sum += A[j][0];
        cost += A[j][1];

        while(i < N && sum > X){
            sum -= A[i][0];
            cost -= A[i][1];
            i++;
        }

        if(cost > best_cost){
            best_cost = cost;
        }

    }

    cout << best_cost << '\n';

    return 0;
}