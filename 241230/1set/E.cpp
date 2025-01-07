
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
ll DP[N];
int mn_depth[N];
pll formul[N];

#define MAX_DIGIT 62

long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

void DFS(int idx, int p){ // {a,b} a*p_parent + b
    if(p!=-1 && edges[idx].size()==1){
        // leaf
        formul[idx]={0,0};
        DP[idx]=0;
        mn_depth[idx]=0;
        return;
    }
    int mnidx=0, mnd=INF;
    for(auto next: edges[idx]){
        if(next==p) continue;
        DFS(next, idx);
        if(mnd>mn_depth[next]){
            mnd=mn_depth[next];
            mnidx=next;
        }
    }
    mn_depth[idx]=mnd+1;
    if(p==-1){
        DP[idx]=0;
    }
    else{
        ll newa, newb;
        ll m=ari_inv(2-formul[mnidx].fi);
        // cout<<idx<<' '<<m<<'\n';
        newa=m;
        newb=formul[mnidx].se*m%MOD;
        formul[idx]={newa,newb};
    }
}

void DFS2(int idx, int p){
    if(p!=-1){
        DP[idx]=(DP[p]*formul[idx].fi+formul[idx].se)%MOD;
    }
    else DP[idx]=1;
    for(auto next : edges[idx]){
        if(next!=p) DFS2(next,idx);
    }
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    DFS(0,-1);
    DFS2(0,-1);
    rng(i,0,n-1) cout<<(DP[i]+MOD)%MOD<<' ';
    cout<<'\n';
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

