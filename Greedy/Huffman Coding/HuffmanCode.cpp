#include <bits/stdc++.h>

struct node{
	int freq;
	char base;
};

int main(){
	std::cin.tie(0)->sync_with_stdio(0);
	freopen("data.txt", "r", stdin);

	std::string C;
	std::cin >> C;

	std::map<char, int> freq;
	for(const char &c: C){
		freq[c]++;
	}

	std::set<node, std::greater<node>> sq;

	for(const auto &[ch, fr]: freq){
		node nd;
		nd.freq = fr;
		nd.base = ch;
		sq.insert(nd);
	}	


    return 0;
}

