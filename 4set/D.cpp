
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

vc<int> edges[N];
ll DP1[N], DP2[N]; // 각각 부모자식없는, 부모자식존재하는

void DFS1(int idx, int p){
    ll temp=1; // DP1은 아무것도 없는 경우도 포함한다.
    for(auto next : edges[idx]){
        if(next!=p){
            DFS1(next,idx);
            temp=(temp*DP1[next])%MOD;
        }
    }
    DP1[idx]=(temp+1)%MOD;
    //cout<<"DP1 "<<idx+1<<' '<<DP1[idx]<<'\n';
}

void DFS2(int idx, int p){
    ll temp=0;
    for(auto next : edges[idx]){
        if(next!=p){
            DFS2(next, idx);
            temp=(temp+DP1[next]-1)%MOD;
        }
    }
    DP2[idx]=temp;
    //cout<<"DP2 "<<idx+1<<' '<<DP2[idx]<<'\n';
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
    DFS1(0,-1);
    DFS2(0,-1);
    ll res=DP1[0];
    rng(i,0,n-1) res=(res+DP2[i])%MOD;
    cout<<(res%MOD+MOD)%MOD<<'\n';
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

