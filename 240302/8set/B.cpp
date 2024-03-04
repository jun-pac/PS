
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
vc<int> val;
ll DP[400];

void Solve(){
    ll n;
    cin>>n;
    if(n<=300) cout<<DP[n]<<'\n';
    else{
        int mul=(n-300)/15;
        cout<<DP[n-mul*15]+mul<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    val.pb(1);
    val.pb(3);
    val.pb(6);
    val.pb(10);
    val.pb(15);
    DP[0]=0;
    rng(i,1,350){
        ll res=DP[i-1]+1;
        rng(j,0,4){
            if(i>=val[j]) res=min(res,DP[i-val[j]]+1);
        }
        DP[i]=res;
        //if(i<=15) cout<<i<<' '<<DP[i]<<'\n';
        //cout<<"DP : "<<i<<' '<<DP[i]<<'\n';
        //if(i>=30) assert(DP[i]==DP[i-30]+2);
        //if(i>=150 && DP[i]!=DP[i-30]+2) cout<<i<<' '<<DP[i]<<' '<<DP[i-30]<<'\n';
    }
    int t=1;
    cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

