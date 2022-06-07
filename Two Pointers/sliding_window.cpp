#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/**
 * Sliding Window Technique
 *
 * Q1. Find the maximum-sum contiguous segement of array of size 3
 *
 **/

int main(){

    int N, X;cin >> N >> X;
    vector<int> A(N);for(int &i : A)cin >> i;

    int len =  INT_MAX;
    int64_t sum = 0;
    for(int i = 0, j = 0 ;j < N; ++j){

        sum += A[j];

        while((sum - A[i]) >= X){
            sum -= A[i];
            i++;
        }

        if(sum >= X)len = min(len, j - i + 1);

    }

    cout << len << "\n";

    return 0;
}