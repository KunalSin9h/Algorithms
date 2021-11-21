/*You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time. */

// This type of question are called as  Activity Selection Problem

#include <bits/stdc++.h>
using namespace std;

// Time -> O(n) where n -> size of array

// function that return the maximum number of activity selected
int activity_selection(int a[], int b[], int n){
    int ans = 0; 
    int pre = -1;
    for(int i = 0;i<n; ++i){
        if(a[i] >= pre){
            ans++;
            pre = b[i];
        }
    }
    return ans;
}


int main(){
    int s[] =  {10, 12, 20};
    int f[] =  {20, 25, 30};
    int n = sizeof(s)/sizeof(s[0]);
    int max_act = activity_selection(s, f, n);
    cout << max_act << endl;
    return 0;
}