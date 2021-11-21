#include <iostream>
using namespace std;

typedef long long ll;

// a utility function for swaping two numbers
void swap(int *a, int *b){
    int c = *b;
    *b = *a;
    *a = c;
}

// time -> O(n^2)
void SelectionSort(int a[], int n){
    for(int i = 0; i<n; ++i){
        int min_ind = i;
        for(int j = i+1;j<n; ++j){
            if(a[min_ind] > a[j])
                min_ind = j;
        }
        swap(&a[i], &a[min_ind]);
    }
}


void print(int a[], int n){
    for(int i = 0;i<n; ++i){
        cout << a[i] << " "; 
    }
    cout << endl;
}

int main(){
    int a[] {3948, 389487, 20, 39887, 2090};
    int n = sizeof(a)/sizeof(a[0]);
    SelectionSort(a, n);
    print(a, n);
    return 0;
}