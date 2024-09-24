
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

ll p[N], a[N], b[N];
vc<int> aval[N];

long long gcd(long long x, long long y){
    if(x<y) swap(x,y);
    if(y==0) return x;
    if(x%y==0) return y;
    return gcd(y,x%y);
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) aval[i].clear();
    rng(i,0,n-1) cin>>p[i];
    rng(i,0,n-1){
        ll g=gcd(i+1,p[i]);
        a[i]=p[i]/g;
        b[i]=(i+1)/g;
    }
    rng(i,0,n-1){
        aval[a[i]].pb(i);  
    }
    // finding pair i<j s.t. a[i] // b[j]==0 and a[j]//b[i]==0 
    rng(aa,1,n){
        // here, i are the value, not indices
        int bb=1;
        while(aa*bb<=n){
            // here, a[i]=aa*bb, b[j]=aa;
            for(auto k : aval[aa*bb]){
                
            }
            bb++;
        }
    }
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

