/*
* A[i] + A[j] <= X
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X;cin >> N >> X;
    vector<int> A(N);
    for(int &i:A)cin >> i;

    sort(A.begin(), A.end());


    function<int(int)> count = [&](int target)->int{
        int cnt = 0;
        for(int i = 0, j = N - 1; i < j; ++i){
            while(i < j && A[i] + A[j] > target)j--;
            cnt += j - i;
        }
        return cnt;
    };


    return 0;
}