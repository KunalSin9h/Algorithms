#include <iostream>
#include <vector>
using namespace std;

// Time -> O(log10(N))
int digit_sum(int n){
    if(n == 0)return 0;
    return n%10 + digit_sum(n/10);
}

void print(vector<int> &a){
    int n = (int) a.size();
    for(int i = 0;i<n; ++i)
        cout << a[i] << " ";
    cout << '\n';
}

void generator(vector<int> &a, int bit, int i){
    if(i == bit){
        print(a);
        return;
    }
    a[i] = 0;
    generator(a, bit, i + 1);
    a[i] = 1;
    generator(a, bit, i + 1);
}

int main(){
    int bit;cin >> bit;
    vector<int> a(bit);

    generator(a, bit, 0);

}
/*
*  Time complexity of RECURSION
*  Time -> (Number of Function Calls) x (iter. on each Function Call)
*  Time Here -> O(N*1) -> O(N)
*/