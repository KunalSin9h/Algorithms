#include <iostream>
using namespace std;

/**
 * You are given two numbers n and k. Find the largest power of k say x, such that n! is divisible by k^x.
 **/

// when k is prime
int fact_pow(int n, int k){
    int res = 0;
    while(n){
        n /= k;
        res += n;
    }
    return res;
}

int main(){

    int n, k;
    cin >> n >> k;

    cout << fact_pow(n, k) << endl;

    return 0;
}