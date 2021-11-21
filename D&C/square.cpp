// A Program to find the largest subsquare Possible given l(lenght) and b(breath)

#include <iostream>
using namespace std;

typedef long long ll;

// USING D&C Algo. and Euclid Algo. -> to just prove that gcd(a, b) == gcd(a, a-b)
int max_square(int l, int b){

    // base case
    if(l == b)
        return l;
    if(l%b == 0)
        return b;
    if(b%l == 0)
        return l;
    
    if( b > l)
        return max_square(l, b-l);
    else if (l > b)
        return max_square(l-b, b);
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l, b;
        cin >> l >> b;
        int side = max_square(l, b);
        
        cout << (l/side)*(b/side) << endl;
    }
    return 0;
}
