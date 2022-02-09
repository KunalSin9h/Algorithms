#include <iostream>
using namespace std;

typedef long long ll;

// Time -> O(n + m);
// Space -> O(n + m);
// Not for negative numbers

int *CountSort(int a[], int n,int m){
    int count[m + 1] = {0};
    for(int i = 0;i<n; ++i){
        count[a[i]]++;
    }
    for(int i = 1;i<=m; ++i){
        count[i] += count[i-1];
    }
    int *output = new int[n];
    for(int i = n-1; i>=0; i--){
        count[a[i]]--;
        output[count[a[i]]] = a[i];
    }
    return output;
}


int main(){
    int n;cin >> n;
    int a[n];
    int m = -1;
    for(int i = 0;i<n; ++i){
        cin >> a[i];
        m = max(m, a[i]);
    }
    int *out = CountSort(a,n, m);
    for(int i = 0;i<n; ++i){
        cout << out[i] << " " ;
    }
    cout << '\n';
    delete [] out;
    return 0;
}