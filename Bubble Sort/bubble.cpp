#include <iostream>
#include <vector>
#include <string>
using namespace std;

void bubble_sort(vector<int> &a, int n){ 
    for(int i = 0;i<n; ++i){
        for(int j = 0;j<n-1; ++j){
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    } 
}

int main(){
    int N;cin >> N;
    vector<int> arr(N);
    for(int &i: arr)cin >> i;

    bubble_sort(arr, N);

    for(const int &i: arr){
        cout << i <<  " " ;
    }
    cout << '\n';
    return 0;
}