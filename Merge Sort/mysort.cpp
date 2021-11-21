#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Merge sort is Not-In Place algo as it required some more(extra) space to perform its duty
// Merge sort is stable 
//Time -> O(nlogn)
// Space ->  O(n);

void Merge(int arr[], int l, int mid, int r){
    // one and two are the count of items in the temp  array
    int one = mid - l + 1;
    int two = r - mid;

    // the two temp array to store the both the halfs on the heap
    int *left = new int[one];
    int *right = new int[two];

    for(int i = 0;i<one; ++i){
        left[i] = arr[l + i];
    }

    for(int i  = 0;i<two; ++i){
        right[i] = arr[mid + 1 + i];
    }

    // initialize the index of the left
    int lft_ind = 0;
    // intialize the index of the rigth
    int rht_ind = 0;
    // initialize the index of the merge_array
    int mer_ind = l;

    // merge the two temp arrays in the main array(merged array)
    while(lft_ind < one && rht_ind < two){
        if(left[lft_ind] <= right[rht_ind]){
            arr[mer_ind] = left[lft_ind];
            lft_ind++;
        }    
        else{
            arr[mer_ind] = right[rht_ind];
            rht_ind++;
        }
        mer_ind++;
    }

    // copy the remaining element of the any array whose element are remaining
    // it may be first 
    while(lft_ind < one){
        arr[mer_ind] = left[lft_ind];
        lft_ind++;
        mer_ind++;
    }
    
    // it may be second array
    while(rht_ind < two){
        arr[mer_ind] = right[rht_ind];
        rht_ind++;
        mer_ind++;
    }
    delete [] left;
    delete [] right;
}


// here l - > low index
// r - > high index
void MergeSort(int arr[], int l, int r){
    if(l >= r)
        return;
    // mid is the middle index where to cut the array
    int mid = l + ((r-l)>>1); // (l+r)/2

    MergeSort(arr, l, mid);
    MergeSort(arr, mid+1, r);
    Merge(arr, l, mid, r);
}


int main(){ 
    int arr[] = {-1, 9, 2, -2, -2, -3, 45, 34};
    int n = sizeof(arr)/sizeof(arr[0]);

    int l = 0;
    int r = n -1;

    MergeSort(arr, l, r);

    for(int i = 0;i<n ;++i){
        cout << arr[i] <<  " " ;
    }
    cout << endl;
    return 0;
}