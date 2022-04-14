#include <iostream>
#include <tuple>
#include <cassert>

int ExEuclid(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    } 
    int g, x1, y1;
    g = ExEuclid(b%a, a, x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return g;
}

/**
 * Linear Diophantine Equation :
 * 
 * find x, y such that ax + by = c 
 * 
 * we find ax0 + by0 = g (g = gcd(a, b)) | simpley by using Extended Euclid
 * 
 * now multipley boty side by (c/g)
 * we get
 * 
 * a(x0*(c/g)) + b(y0*(c/g)) = c
 * 
 * hence x = x0*(c/g)
 * and   y = y0*(c/g)
 * 
 * provided c%g == 0
 * 
 **/
bool LDE(int a, int b, int c, int &x, int &y, int &g){
    g = ExEuclid(abs(a), abs(b), x, y);
    if(c%g){
        return false;
    }
    x *= (c/g);
    y *= (c/g);
    x *= (a < 0 ? -1 : 1);
    y *= (b < 0 ? -1 : 1);
    return true;
}

int main(){
    int a, b, c;
    std::cin >> a >> b >> c;
    // degenerate case
    if(a == 0 && b == 0){
        std::cout << ( c == 0 ? "INFINITY MANY SOLUTIONS" : "NO SOLUTIONS") << '\n';
    }
    else{
        int x, y, g;
        bool sol = LDE(a, b, c, x, y, g);
        if(sol){
            std::cout << x << ' ' << y << '\n';
        }
        else std::cout << "SOLUTION DOES NOT EXIST" << '\n';
    }

    return 0;
}