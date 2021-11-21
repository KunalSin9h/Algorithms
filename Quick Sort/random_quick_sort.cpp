#include <iostream>
#include <cstdlib>    // For Random number
using namespace std;

// a utility function to swap two numbers
void swap(int *a, int *b){
    int c = *b;
    *b = *a;
    *a = c;
}

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */

int partition(int arr[], int low, int high){
    int pivot = arr[high]; // pivot
    int i = (low - 1);

    for(int j = low; j <= high - 1; ++j){
        //if current element is smaller than  the pivot
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */

void QuickSort(int arr[], int low, int high){
    if(low < high){
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int r = rand()%(high+1) + low; // random number between low and high
        swap(&arr[low], &arr[r]);
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);       
    }
}

// function to print the array

void print(int a[], int size){
    for(int i = 0;i<size; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}


int main(){
    int arr[] = {1, 1, 1, 1, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    QuickSort(arr, 0, n-1);
    cout << "Sorted Array" << endl;
    print(arr, n);
    
    return 0;
}