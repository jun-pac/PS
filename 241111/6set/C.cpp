
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

map<pii,int> st;
vc<pii> dir;

void Solve(){
    dir.pb({-1,-2});
    dir.pb({1,-2});
    dir.pb({-1,2});
    dir.pb({1,2});
    dir.pb({-2,-1});
    dir.pb({-2,1});
    dir.pb({2,-1});
    dir.pb({2,1});

    ll n,m;
    cin>>n>>m;
    ll cnt=0;
    rng(i,0,m-1){
        ll a,b;
        cin>>a>>b;
        a--, b--;    
        if(st[{a,b}]==0){
            st[{a,b}]=1;
            cnt++;
        }
        rng(j,0,7){
            ll na=a+dir[j].fi;
            ll nb=b+dir[j].se;
            if(na<0 || na>=n || nb<0 || nb>=n) continue;
            if(st[{na,nb}]==0){
                st[{na,nb}]=1;
                cnt++;
            }
        }
    }
    cout<<n*n-cnt<<'\n';
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

