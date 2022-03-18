#include <bits/stdc++.h>
using namespace std;

/*
* A[i] + A[j] + A[k] == X
*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;cin >> N >> X;
    vector<int> A(N);
    for(int &i:A)cin >> i;

    sort(A.begin(), A.end());

    function<bool(int, int)> Sum_2 = [&](int l, int target)->bool{
        for(int i = l, j = N - 1; i < j; ++i){
            while(i < j && A[i] + A[j] > target)j--;
            if(i != j &&  A[i] + A[j] == target){
                return true;
            }
        }
        return false;
    };

    for(int i = 0;i<N; ++i){
        // Fix A[i];
        int need = X - A[i];
        bool possible = Sum_2(i + 1, need);
        if(possible){
            cout << "Yes" << '\n';
            exit(0);
        }
    }
    cout << "Not" << '\n';
    return 0;
}