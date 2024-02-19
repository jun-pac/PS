// 
//./D<test.txt

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

int p[100000];
int depth[100000];
vector<int> edges[100000];

int depth_DFS(int idx){
	int d=0;
	for(int i=0; i<edges[idx].size(); i++){
		d=max(d,depth_DFS(edges[idx][i]));
	}
	d++;
	depth[idx]=d;
	return depth[idx];
}

int mx_DFS(int idx){
	int mx=0;
	for(int i=0; i<edges[idx].size(); i++){
		mx=mx+mx_DFS(edges[idx][i]);
	}
	return max(mx,depth[idx]);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, a;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a;
		p[i+1]=a-1;
		edges[a-1].push_back(i+1);
	}
	depth_DFS(0);
	cout<<mx_DFS(0)<<endl;

	return 0;
}

/*
4
1 2 2
=> 3
*/

/*
5
1 2 3 1
=>4
*/