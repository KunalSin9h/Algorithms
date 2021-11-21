#include <iostream>
using namespace std;

typedef long long ll;

int minind(int a[], int n){
    int min_el = a[0];
    int min_ind = 0;
    for(int i = 1; i<n; ++i){
        if(a[i] < min_el){
            min_el = a[i];
            min_ind = i;
        }
    }
    return min_ind;
}

int secmin(int a[], int n){
    int min_ind = 0;
    for(int i = 1;i<n; ++i){
        if(a[min_ind] > a[i])
            min_ind = i;
    }   

    return min_ind;
}


int main(){
    int n = 12;
    int a[n] {-1, 34, 45, 23, 56, 10, 13, 100, 10, 2234, 1000, 0};
    cout << minind(a, n) << endl;
    cout << secmin(a, n) << endl;
    return 0;
}