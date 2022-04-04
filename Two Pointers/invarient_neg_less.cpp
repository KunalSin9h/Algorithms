#include "bits/stdc++.h"
using namespace std;

// A[i] - A[j] <= X

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;
    cin >> N >> X;
    vector<int> A(N);for(int &i: A)cin >> i;
    sort(A.begin(), A.end());

    for(int i = 0, j = 0; i < N; ++i){
        while(j < N && A[j] - A[i] < X)j++;
        if(j < N && A[j] - A[i] == X){
            cout << A[j]  <<  ' ' << A[i] << '\n';
        }
    }

    return 0;
}