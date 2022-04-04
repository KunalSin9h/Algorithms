#include <bits/stdc++.h>
using namespace std;

/*
*  Euclid Algorithm: To find Gcd of (a, b) Recursively
*  Time -> O(log (min(a, b))) 
*/
int Euclid(int a, int b){
    if(a == 0)  
        return b;
    return Euclid(b%a, a);
}

int Euclid_2(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if( a >= b)
        return Euclid_2(a - b, b);
    else return Euclid_2(a, b - a);
}

int Euclid_3(int a, int b){
    int c;
    while(b){
        c = b;
        b = a%b;
        a = c;
    }
    return a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}