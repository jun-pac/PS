
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
vc<ll> DP[N]; // number of nodes, by depth(Max depth in 0 index)
ll subsz[N];
ll res;

void DFS(int idx, int p){
    if(p!=-1 && edges[idx].size()==1){
        DP[idx].pb(1);
        subsz[idx]=1;
        return;
    }
    vc<int> child;
    for(int next : edges[idx]) if(next!=p) child.pb(next);

    // assert(child.size() != 0);
    rng(i,0,(int)child.size()-1){
        int next=child[i];
        DFS(next,idx);
        if(DP[child[0]].size() < DP[next].size()){
            swap(child[0],child[i]);
        }
    }
    int idxa=child[0];
    
    for(auto next : child){
        // cout<<"nei "<<idx+1<<' '<<next+1<<'\n';
        if(next==idxa) continue;
        ll adepth=DP[idxa].size();
        ll bdepth=DP[next].size();
        // assert(adepth>=bdepth);
        ll asum=0;
        ll anum=0;
        // cout<<"debug "<<idx+1<<' '<<adepth<<' '<<bdepth<<'\n';
        rng(d,0,bdepth-1){
            asum+=(2*d+1)*DP[idxa][adepth-1-d];
            anum+=DP[idxa][adepth-1-d];
            res+=(asum)*DP[next][bdepth-1-d]; // depth(a_side) <= depth(b_side)
            res+=(2*d+1)*(subsz[idxa]-anum)*DP[next][bdepth-1-d];
            // cout<<asum<<' '<<anum<<' '<<(asum)*DP[next][bdepth-1-d]<<' '<<(2*d+1)*(subsz[idxa]-anum)*DP[next][bdepth-1-d]<<'\n';
        }
        // merge!
        rng(d,0,bdepth-1) DP[idxa][adepth-1-d]+=DP[next][bdepth-1-d]; 
        subsz[idxa]+=subsz[next];
    }
    // Crankup
    swap(DP[idx],DP[idxa]);
    swap(subsz[idx], subsz[idxa]);
    DP[idx].pb(1);
    subsz[idx]++;
} 

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) DP[i].clear();
    rng(i,0,n-1) subsz[i]=0;

    rng(i,0,n-2){
        int u,v;
        cin>>u>>v;
        u--, v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    if(n==1){
        cout<<0<<'\n';
        return;
    }
    res=0;
    DFS(0,-1);
    cout<<res<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

