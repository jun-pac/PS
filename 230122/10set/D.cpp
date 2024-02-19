// 
//./E<test

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

vector<int> edges[200000];
ll depth[200000];

#define MOD 1000000007

void DFS(int idx, int parent){
    ll d=1;
    for(int i=0; i<edges[idx].size(); i++){
        int next=edges[idx][i];
        if(next!=parent){
            DFS(next,idx);
            d=max(d,depth[next]+1);
        }
    }
    depth[idx]=d;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++) edges[i].clear();
        int a,b;
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--,b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        fill(depth,depth+n,-1);
        DFS(0,-1);
        ll res=0;
        for(int i=0; i<n; i++) res=res+depth[i];
        for(int i=0; i<n-1; i++) res=(res*2)%MOD;
        cout<<res<<endl;
    }
    return 0;
}