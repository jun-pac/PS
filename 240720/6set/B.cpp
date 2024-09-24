
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

pii pos[3];
bool check(int a, int b, int c){
    //cout<<a<<' '<<b<<' '<<c<<' '<<(pos[b].fi-pos[a].fi)*(pos[c].se-pos[a].se)<<' '<<(pos[b].se-pos[a].se)*(pos[c].fi-pos[a].fi)<<'\n';
    return ((pos[b].fi-pos[a].fi)*(pos[c].fi-pos[a].fi)+(pos[b].se-pos[a].se)*(pos[c].se-pos[a].se)==0);
}

void Solve(){
    rng(i,0,2) cin>>pos[i].fi>>pos[i].se;
    if(check(0,1,2) || check(1,2,0) || check(2,1,0)) cout<<"Yes\n";
    else cout<<"No\n";
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

