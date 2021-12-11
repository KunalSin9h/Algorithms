// Naive Algo To Find the Subsequence With Max Sum
// Time -> O(n^2)
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;


int main(){
    vector<int> given{-5, 4, 3, -1, 4, -1};


    int max_sum = -1e9;

    int n = given.size();
    for(int i = 0;i<n; ++i){
        int curr = 0;
        for(int j = i;j <n; ++j){
            curr = curr + given.at(j);
            if(curr > max_sum)
                max_sum = curr; 
        } 
       
    }
    cout << max_sum << endl;

    return 0;
}