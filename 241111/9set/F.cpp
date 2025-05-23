
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)  
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
typedef long long ll;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

#define N 300030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N];
int deg[N];
int visited[N];

int DFS(int idx){
    visited[idx]=1;
    int res=0;
    for(auto next : edges[idx]){
        if(deg[next]==3 && !visited[next]) res+=DFS(next);
        else if(deg[next]==2) res++;
    }
    return res;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,n-1) deg[i]=edges[i].size();
    ll res=0;
    rng(i,0,n-1){
        if(deg[i]==3 && !visited[i]){
            ll val=DFS(i);
            res+=val*(val-1)/2;
        }
    }
    ll tt=0;
    rng(i,0,n-1){
        if(deg[i]==2){
            for(auto next: edges[i]){
                if(deg[next]==2) tt++;
            }
        }
    }
    tt/=2;
    //cout<<tt+res<<'\n';
    //cout<<tt<<' '<<res<<'\n';
    cout<<res<<'\n';
}  

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

