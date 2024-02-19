// 
//./D<test

#include <bits/stdc++.h>
#define endl '\n'
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;

template<typename T>
inline T umax(T &u, T v){return u = max(u, v);}
template<typename T>
inline T umin(T &u, T v){return u = min(u, v);}

#define N 200020

int datas[N];
vector<int> edges[N];
ll DP[N];
ll DFS(int idx, int p){
    ll res=0;
    for(auto next : edges[idx]){
        if(next!=p) res+=DFS(next,idx);
    }
    if(res==0) res=1;
    DP[idx]=res;
    return DP[idx];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        DFS(0,-1);
        int q;
        cin>>q;

        for(int i=0; i<q; i++){
            cin>>a>>b;
            a--, b--;
            cout<<DP[a]*DP[b]<<endl;
        }
    }
    return 0;
}