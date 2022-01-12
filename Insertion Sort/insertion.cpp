#include <iostream>
using namespace std;

typedef long long ll;

int main(){

    int n;cin >> n;
    int arr[n];
    for(int i = 0;i<n; ++i){
        cin >> arr[i];
    }

    /*
    * Algo -> Insetion Sort
    * Time -> O(n^2)
    * Time (Best) -> O(n) == When array is already sorted
    * Space -> O(1)
    * inplace -> YES
    * Stable -> YES
    */

    for(int  i = 1;i<n; ++i){
        int curr = arr[i];
        int j = i - 1;
        while(arr[j] > curr && j >= 0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }
    for(int i = 0;i<n; ++i){
        cout << arr[i] << " " ;
    }
    cout << endl;
    return 0;
}