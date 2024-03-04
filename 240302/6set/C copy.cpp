
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

#define N 40030
#define MOD 1000000007
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))


ll powa[22], powb[22];
map<ll,ll> mp;

void Solve(){
    ll a,b,x;
    cin>>a>>b>>x;
    ll cur=1;
    int aa=0;
    mp.clear();
    while(cur<=x){
        powa[aa]=cur;
        aa++;
        cur*=a;
    }
    cur=1;
    int bb=0;
    while(cur<=x){
        powb[bb]=cur;
        bb++;
        cur*=b;
    }

    int cnt=0;
    rng(i,0,aa-1){
        rng(j,0,bb-1){
            ll res=powa[i]*powb[j];
            if(x%res==0){
                if(mp[x/res]==0) cnt++;
                mp[x/res]++;
            }
        }
    }
    cout<<cnt<<'\n';
    
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

