#include <bits/stdc++.h>
using namespace std;

int inv(int a, int m){
    int p = 0, q = 0;
    while(a != 0){
        int t = m/a;
        m -= t*a;
        swap(a, m);
        p -= t*q;
        swap(p, q);
    }
    assert(m == 1);
    return p;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}