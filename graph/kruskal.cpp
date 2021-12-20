#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

// DEBUG 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<": "<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#define dbg_time() cerr << "\e[91m" << "Time: " << __LINE__ << " = [ " << ((db)(clock()-beg)/CLOCKS_PER_SEC)  << " ]" << "\e[39m"<< endl;
#else
#define dbg(x...)
#define dbg_time()
#endif

// Union - Find (Disjoint Set)
struct union_find{
private:
    vector<int> parent, rank;
public:
    union_find(int n){ 
        parent.resize(n, 0);
        rank.resize(n, 0);
        for(int i = 0;i<n; ++i){parent[i] = i;}
    }
    int find(int x){
        if(parent[x] == x)return x;
        else return  parent[x] =  find(parent[x]);
    }
    void unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y)return;
        if(rank[x] < rank[y]){
            parent[x] = y;
        }
        else{
            parent[y] = x;
            if(rank[x] == rank[y])rank[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    } 
};


int main(){
	// Implementing Kruskal's Algo. to find the minimum spanning tree
	int v, m;
	cin >> v >> m;
	vector<array<int, 3>> graph(m);
	for(int i = 0;i<m; ++i)
		cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
	
	sort(begin(graph), end(graph));

	union_find gp(v);
	int minimum_wt = 0;

	for(auto &[wt, a, b]: graph){
		if(!gp.same(a, b)){
			minimum_wt += wt;
			gp.unite(a, b);
		}
	}
	dbg(minimum_wt);
	cout << minimum_wt << nl;
	
	return 0;
}

