#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    vector<int> a{5, 10, 6, 4, 3, 2, 6, 7, 9, 3};
    nth_element(a.begin(), a.begin() + 4, a.end());
    cout << a[4] << '\n'; 
    return 0;
}