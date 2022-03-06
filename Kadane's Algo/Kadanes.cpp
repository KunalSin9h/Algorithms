// Kadane's algo to find the subseq with max_sum
// Time -> O(n)
// Limitatin: Does not work(need adjustment) in case of all negative

#include <iostream>
using namespace std;

typedef long long ll;

int MaxSum(int a[], int n){
    int max_sum = 0; 
    int curr_sum = 0;
    for(int i = 0;i<n; ++i){
        curr_sum += a[i];
        if(curr_sum > max_sum)
            max_sum = curr_sum;
        if(curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}

int main(){
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        int a[n];
        for(int i; i<n; ++i)cin >> a[i];

        int sum = MaxSum(a, n);
        cout << sum << '\n';
    }
    return 0;
}