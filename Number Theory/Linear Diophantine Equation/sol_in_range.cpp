#include "bits/stdc++.h"
using namespace std;

int exEuclid(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    int g, x1, y1;
    g = exEuclid(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return g;
}

bool LDE(int a, int b, int c, int &x, int &y, int &g){
    g = exEuclid(abs(a), abs(b), x, y);
    if(c%g)return false;
    x *= (c/g);
    y *= (c/g);
    if(a < 0)x = -x;
    if(b < 0)y = -y;
    return true;
}

void shift_sol(int &x, int &y, int a, int b, int cnt){
    x += cnt*b;
    y -= cnt*a;
}

#define dbg(x) cout << #x << " -> " << x << '\n';

int find_all_sol(int a, int b, int c, int x_min, int x_max, int y_min, int y_max){
    int x, y, g;
    if(LDE(a, b, c, x, y, g) == false)return 0;
    a /= g;
    b /= g;
    int sign_a = a > 0 ? 1 : -1;
    int sign_b = b > 0 ? 1 : -1;
    shift_sol(x, y, a, b, (x_min - x)/b);

    if(x < x_min)shift_sol(x, y, a, b, sing_b);
    if(x > x_max) return 0;

    int lx1 = x;

    shift_sol(x, y, a, b, (x_max - x)/b);

    if(x > x_max)shift_sol(x, y, a, b, -sign_b);

    int rx1 = x;

    shift_sol(x, y, a, b, -(y_min - y)/a);

    if(y < y_min)shift_sol(x, y, a, b, -sign_a);
    if (y > y_max)return 0;

    int lx2 = x;

    shift_sol(x, y, a, b, -(y_max - y)/a);
    if(y > y_max)shift_sol(x, y, a, b, sign_a);

    int rx2 = x;

    if(lx2 > rx2){
        swap(lx2, rx2);
    }
    
    int lx = max(lx1, lx2);
    int rx = max(rx1, rx2);
    if(lx > rx)return 0;
    
    return (rx - lx)/abs(b) + 1;

}

int main(){
    int a = 2, b = 2, c = 4;
    find_all_sol(a, b, c, 1, 1, 1, 1);
    return 0;
}