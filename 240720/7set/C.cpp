
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
vc<ll> datas;
void Solve(){
    ll n;
    cin>>n;
    datas.clear();
    rng(i,0,59){
        if((1LL<<i)&n){
            datas.pb((1LL<<i));
        }
    }
    if(datas.size()==1){
        cout<<1<<'\n';
        cout<<n<<'\n';
        return;
    }
    cout<<datas.size()+1<<'\n';
    ll tot=0;
    rng(i,0,(int)datas.size()-1){
        tot+=datas[i];
    }
    gnr(i,(int)datas.size()-1,0){
        cout<<tot-datas[i]<<' ';
    }
    cout<<tot<<'\n';

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

