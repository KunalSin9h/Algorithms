#include "bits/stdc++.h"
using namespace std;

// huffman coding
struct MinHeapNode {
    char data;
    unsigned freq;
    MinHeapNode *left, *right;
    MinHeapNode(char data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    return 0;
}