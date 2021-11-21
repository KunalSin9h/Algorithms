#include <iostream>
using namespace std;

typedef long long ll;

void Merge(int arr[], int l, int mid, int r){
    int one = mid - l + 1 ;
    int two = r - mid;

    // create two temp arrays
    int *left = new int[one];
    int *right = new int[two];

    // Copy data to temp arrays leftarray[] and rightarray[];
    for(int i = 0;i<one; ++i){
        left[i] = arr[l+i];
    }
    for(int j = 0;j<two; ++j){
        right[j] = arr[mid + 1 + j];
    }
    // initialize index of first sumbarray
    int fir_ind = 0;
    // initialize index of second subarray
    int sec_ind = 0;
    // initialize index of merged subarray
    int mer_ind = l;

    // Merged the temp array back into arr[l...r]
    while(fir_ind < one && sec_ind < two){
        if(left[fir_ind] <= right[sec_ind]){
            arr[mer_ind] = left[fir_ind];
            fir_ind++;
        }
        else{
            arr[mer_ind] = right[sec_ind];
            sec_ind++;
        }
        mer_ind++;
    }
    // May be Some Element might not get change to include 
    // copy the remaining element of left array if any remainig
    while(fir_ind < one){
        arr[mer_ind] = left[fir_ind];
        fir_ind++;
        mer_ind++;
    }
    // copy the remaining element of the right array if any remainig
    while(sec_ind < two){
        arr[mer_ind] = right[sec_ind];
        sec_ind++;
        mer_ind++;
    }

    delete [] left;
    delete [] right;
}

void MergeSort(int arr[], int l, int r){
    // base case
    if(l >= r)
        return;
    
    int mid = l + ((r-l)>>1);
    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    Merge(arr, l, mid, r);

}

// a Utility Function to print all the element of the array
void print_array(int arr[], int n){
    for(int i = 0;i<n; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = { 10, 3, 2, 1, 7, 9, 4, 5,6, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    MergeSort(arr, 0, n-1);

    print_array(arr, n);
    return 0;
}