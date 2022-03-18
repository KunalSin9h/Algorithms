#include <bits/stdc++.h>
using namespace std;

/*
* A[i] + A[j] == X
*/

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;cin >> N >> X;
    vector<int> A(N);
    for(int &i:A)cin >> i;

    sort(A.begin(), A.end());

    function<int(int)> Sum_2 = [&](int target)->int{
        for(int i = 0, j = N - 1; i < j; ++i){
            while(i < j && A[i] + A[j] > target)j--;
            if(i != j &&  A[i] + A[j] == target){
                cout << A[i] << " " << A[j] << '\n';
            }
        }
    };

    return 0;
}
