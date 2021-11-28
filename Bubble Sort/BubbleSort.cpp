#include <iostream>
using namespace std;

typedef long long ll;

// Utility Function For Swaping Two Numbers
void swap(int *a, int *b){
    int c = *b;
    *b = *a;
    *a = c;
}

// Algo-> Bubble Sort
// Time -> O(n^2)
// Space -> O(1):
// Inplace -> Yes
// Stable -> Yes
void BubbleSort(int arr[], int n){
    bool isSorted = false;
    int lastPass = n-1;
    while(!isSorted){
        isSorted = true;
        for(int i = 0;i<lastPass; ++i){
            if(arr[i] > arr[i+1]){
                swap(&arr[i], &arr[i+1]);
                isSorted = false;      
            }
        }
        lastPass--; // Little Bit optimization
    }
}

void Bubble2(int arr[], int n){
    int counter = 1;
    while(counter < n){
        for(int i = 0;i<n-counter; ++i){
            if(arr[i] > arr[i+1]){
                int temp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = temp;
            }
        }
        counter++;
    }


}

int main(){
    int arr[] = {13, 3, 3544, 45, 32, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr, n);
    for(int i = 0;i<n; ++i){
        cout << arr[i] << " ";
    }   
    cout << endl;
    return 0;
}