#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int n;

void print(vector<int> &c){
	for(int &i: c)cout << i << " ";
	cout << '\n';
}
vector<int> b;
vector<bool> used;
void permu(){
	if(b.size() == n){
		print(b);
		return;
	}
	
	for(int i = 0;i<n; ++i){
		if(used[i])continue;
		used[i] = true;
		b.push_back(a[i]);
		permu();
		b.pop_back();
		used[i] = false;
	}
}

int main(){
	cin >> n;
	a.resize(n);
	for(int &i: a)cin >> i;
	used.resize(n, false);
	cout << "Ans " << "\n";
	permu();
	
	return 0;
}