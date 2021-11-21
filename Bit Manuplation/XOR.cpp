#include <iostream>
using namespace std;

typedef long long ll;

//  Question 1 ->>
/* Find the only non-repeating element in the array
where every element repeate twice
*/




// Question 2  ->>
/* Find the two non -repeating elemnt in the array
where every element repeate twice
*/
// sol..

int sol2(int arr[], int n){
    int result = 0;
    for(int i = 0; i<n; ++i)
        result = result^arr[i];

    // result = a^b -> the two non-repeating element
    
}




int main(){
    
    return 0;
}