
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll lmx[N], rmx[N];
bool visited[N];
pll datas[N];

void Solve(){
    int n,q;
    cin>>n>>q;
    rng(i,0,q-1) cin>>lmx[i];
    rng(i,0,q-1) cin>>rmx[i];
    fill(visited,visited+n,0);
    visited[n-1]=1;
    rng(i,0,q-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        if(visited[a]==visited[b]){
            cout<<0<<'\n';
            return;
        } 
        visited[a]=1;
        visited[b]=1;
    }
    ll mul=1;
    rng(i,0,q-1) mul=(mul*2)%MOD;



}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while(t--){
        Solve();
    }
    return 0;
}

