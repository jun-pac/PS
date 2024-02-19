
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

ll calc(ll k, ll n){
    ll res=1;
    ll mul=1;
    rng(i,0,n-1){
        mul*=k;
        res+=mul;
        if(mul>1e18 || res>1e18) return 2e18;
    }
    return res;
}

void Solve(){
    ll x;
    cin>>x;
    rng(i,2,58){
        //cout<<"N : "<<i<<'\n';
        ll l=2;
        ll r=pow((double)1e18, (double)1/i);
        //cout<<l<<' '<<r<<endl;
        while(l!=r){
            ll mid=(l+r)>>1;
            //cout<<"mid "<<mid<<' '<<calc(mid,i)<<'\n';
            if(calc(mid,i)>=x) r=mid;
            else l=mid+1;
        }
        //cout<<"L "<<l<<' '<<calc(l,i)<<'\n';
        if(calc(l,i)==x){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO\n";
    return;
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

