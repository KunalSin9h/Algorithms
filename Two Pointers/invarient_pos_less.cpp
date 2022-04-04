#include "bits/stdc++.h"
using namespace std;

// A[j] - A[i] >= X; // Relative Position is not allowed in negatives

/**
* in case of A[i] + A[j] <= X we can do it A[j] + A[i] <= X thats why sorting does not effect
**/

// so we have to take extra measure to insure the i < j(or any) be not voilated

int main(){
    cin.tie(0)->sync_with_stdio(0);
	int N , X;cin >> N >> X;
	vector<array<int, 2>> A(N);
	for(int i = 0; i < N; ++i){
		cin >> A[i][0];
		A[i][1] = i;
	}
	sort(A.begin(), A.end(), [&](auto &p, auto &q)->bool{
		return p[0] < q[0];
	});	

	for(int i = 0, j = 0; i < N; ++i){
		while(j < N && A[j][0] - A[i][0] < X)j++;
		if(A[j][0] - A[i][0] == X && A[i][1] < A[j][1]){
			cout << A[i][0] << " " << A[j][0] << '\n';
		}
	}

    return 0;
}
