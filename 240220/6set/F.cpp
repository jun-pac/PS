
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

vc<int> edges[10000];
ll a[10000];
ll w[10000];
pll info[10000];
ll mul[10000];
ll DP[10000]; // for knapsack


void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,n-1) cin>>w[i];
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) info[i]={w[i],i};
    sort(info,info+n);
    // 가장 작은 원소부터
    rng(i,0,n-1){
        int idx=info[i].se;
        assert(w[idx]==info[i].fi);
        fill(DP,DP+w[idx],0);
        for(auto next : edges[idx]){
            if(w[next]<w[idx]){
                //DP[w[next]]=max(DP[w[next]],mul[next]);
                gnr(j,w[idx]-1,w[next]) DP[j]=max(DP[j],DP[j-w[next]]+mul[next]); // 이런 DP를 왜 틀리냐 시발롬아
            }
        }
        mul[idx]=0;
        rng(j,0,w[idx]-1) mul[idx]=max(mul[idx],DP[j]);
        mul[idx]++;
        //cout<<"DP : "; rng(j,0,w[idx]-1) cout<<DP[j]<<' '; cout<<'\n';
        //cout<<idx+1<<' '<<mul[idx]<<'\n';
    }

    ll res=0;
    rng(i,0,n-1) res+=a[i]*mul[i];
    cout<<res<<'\n';
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

