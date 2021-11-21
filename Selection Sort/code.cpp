#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> elements(n);
    for(int i = 0;i<n; ++i){
        cin >> elements[i];
    }
    vector<int> sorted;
    // Code for Selection Sort-> 
    // sort in Decending order
    while(n--){
        auto m = min_element(begin(elements), end(elements));
        sorted.push_back(*m);
        elements.erase(m);
    }
    for(int &i: sorted){
        cout << i << " " ;
    }
    cout << endl;
    return 0;
}