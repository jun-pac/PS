
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

vc<ll> vals;
string s;
ll n;

int solve(ll k){
    if(k<=n) return s[k-1];
    ll idx=0;
    while(vals[idx+1]<k){
        idx++;
    }
    // cout<<"de "<<k<<' '<<vals[idx]<<'\n';
    int res=solve(k-vals[idx]);
    // cout<<"DEG "<<(char)res<<'\n';
    return (res<='Z'?res+'z'-'Z':res+'Z'-'z'); 
}

void Solve(){
    cin>>s;
    n=s.size();
    ll temp=n;
    while(temp<=2000000000000000000){
        vals.pb(temp);
        temp=temp*2;
    }

    ll q;
    cin>>q;
    rng(i,0,q-1){
        ll x;
        cin>>x;
        cout<<(char)solve(x)<<' ';
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

