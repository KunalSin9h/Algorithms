// the idea is for handling the negative numbers is to just increase the range
// for example if only positive numbers then in numberline if max is 6 then we set the range to 6 + 1;
// bcoz 6 + 0th number in number in number line

// now that we have negitive nubers we increase range in numberline includeing ex. -2 -> 4 
// total of 4 - (-2) + 1;

#include <bits/stdc++.h>
using namespace std;

int *CountSort(int a[], int n, int l, int h){
    int r = h - l + 1;
    int count[r] = {0};

    int *output = new int[n];

    for(int i = 0;i<n; ++i){
        count[a[i] - l]++;
    }
    for(int i = 1;i<r; ++i){
        count[i] += count[i-1];
    }
    for(int i = n-1;i>=0; --i){
        output[(count[a[i] - l]) - 1] = a[i];
        count[a[i] - l]--;
    }
    return output;
}

int main(){
    int n; cin >> n;
    int a[n];
    int l = 1e9;
    int h = -1;
    for(int i = 0;i<n; ++i){
        cin >> a[i];
        l = min(l, a[i]);
        h = max(h, a[i]);
    }
    int *out = CountSort(a, n, l, h);
    for(int i = 0;i<n; ++i){
        cout << out[i] << ' ';
    }
    cout << endl;
    delete [] out;
    return 0;
}
