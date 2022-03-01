#include <bits/stdc++.h>
using namespace std;

/* Problem: d = gcd(a, b)
*  d = a*x + b*y
*  find x and y 
*/

/* Extended Euclid Algorithm is used to find this solution of equation
*  'd' can be found easly by Euclid Algo. but we also want to find 'x' and 'y'
*
*  Time -> O(log max(a, b))
*  Usage -> finding Modular inverse
*/
int Extended_Euclid(int a, int b, int* x, int* y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b; // Gcd
    }

    int x1 = 0, y1 = 0;
    int d = Extended_Euclid(b%a, a, &x1, &y1);
    *x = y1 - x1*(b/a);
    *y = x1;
    return d;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a = 999;
    int b = 1000;
    // a*x + b*y = gcd(a, b) = d
    // to find = (d, x, y)
    int x = 0, y = 0;
    int d = Extended_Euclid(a, b, &x, &y);

    cout << d << " " << x << " " << y << '\n';    

    return 0;
}