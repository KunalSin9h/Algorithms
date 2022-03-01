#include <bits/stdc++.h>
using namespace std;

int Extended_Euclid(int a, int b, int *x, int *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }

    int x1 = 0, y1 = 0;
    int d = Extended_Euclid(b%a, a, &x1, &y1);
    *x = y1 - x1*(b/a);
    *y = x1;
    return d;
}

int inverse(int a, int b){
    int x = 0, y = 0;
    int d = Extended_Euclid(a, b, &x, &y);
    if(d == 1)
        return x;
    return  -1; // Inverse Not Possible
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a;int b;
    cin >> a >> b;

    cout << inverse(a, b) << '\n';

    return 0;
}