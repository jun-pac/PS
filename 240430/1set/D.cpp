
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

#define N 200030

vc<ll> edges[N];
ll sz[N], sumsz[N];
ll perm[N];

void tree_DFS(int idx, int p){
    ll cur=1;
    ll sum=0;
    for(int next : edges[idx]){
        if(next!=p){
            tree_DFS(next, idx);
            cur+=sz[next];
            sum+=sumsz[next];
        }
    }
    sz[idx]=cur;
    sumsz[idx]=sum+sz[idx];
}

void DFS(ll idx, ll p, ll val, ll low, ll high){
    if(val>=sz[idx]-1){
        perm[idx]=low;
        val-=(sz[idx]-1);
        low++;
    }
    else{
        perm[idx]=high;
        high--;
    }
    for(int next : edges[idx]){
        if(next!=p){
            DFS(next, idx, min(val,sumsz[next]-sz[next]), low, low+sz[next]-1);
            val=val-min(val,sumsz[next]-sz[next]);
            low=low+sz[next];
        }
    }
}



void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-2){
        ll a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    tree_DFS(0,-1);
    if(n<=k && k<=sumsz[0]){
        cout<<"Yes\n";
        DFS(0,-1,k-n,1,n);
        rng(i,0,n-1) cout<<perm[i]<<' ';
    }
    else{
        cout<<"No\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

