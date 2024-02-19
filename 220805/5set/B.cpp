// 
//./B<test

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

vector<pair<int,int>> edges[200020]; // next, order
int res;
 
void DFS(int idx, int parent, int num_inv, int p_order){
    for(auto next:edges[idx]){
        if(next.fi==parent) continue;
        if(next.se>p_order) DFS(next.fi, idx, num_inv, next.se);
        else DFS(next.fi, idx, num_inv+1, next.se);
    }
    if(edges[idx].size()==1) res=max(res,num_inv);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n;
        res=0;
        for(int i=0; i<n; i++) edges[i].clear();
        for(int i=0; i<n-1; i++){
            cin>>a>>b;
            a--, b--;
            edges[a].push_back({b,i+1});
            edges[b].push_back({a,i+1});
        }
        //fill(visited,visited+n,0);
        DFS(0,-1,0,-1);
        cout<<res+1<<endl;
    }
    return 0;
}