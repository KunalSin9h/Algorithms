#include <iostream>
using namespace std;

typedef long long ll;

int sum_recur(int a[], int l, int r){
    if(l == r)
        return a[l];
    return a[l] + sum_recur(a, l + 1, r);
}   

int count_item(int a[], int l, int r, int c){
    if(l > r){
        return c;
    }
    c++;
    return count_item(a, l+1, r, c);
}

int max_item(int a[], int l, int r, int m){
    // base case 
    if(l > r)
        return m;
    m = max(m, a[l]);
    return max_item(a, l+1, r, m);
}

int main(){
    // find the sum
    int a[] {1, 2, 3, 4, 5, 6, 7, 13, 8, 9, 10, 11};
    int n = sizeof(a)/sizeof(a[0]);

    int sum = sum_recur(a, 0, n-1);
    cout << sum << endl;

    // count the items
    int c = 0;
    int count = count_item(a, 0, n-1, c);
    cout << "Count " << count << endl;
    
    //find the max item in the list
    int m = a[0];
    int mx = max_item(a, 0, n-1, m);
    cout << mx << endl;
    
    return 0;
}