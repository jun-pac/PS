
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)


void Solve(){
    ll n,m;
    cin>>n>>m;
    // 결국에는 하나의 edge에서, 1,...,M의 값이 MST로 등장할 확률을 구한다면 모든 게 해결된다.
    // MST는 작은 edge부터 시작해서 붙여나가는 방식
    ll res=0;
    rng(k,0,n-2){
        for(ll i=1; i<=m; i++){
            ll val1=1;
            rng(j,0,n-k-2) val1=val1*(m+1-i)%MOD;
            ll val2=1;
            rng(j,0,n-k-2) val2=val2*(m-i)%MOD;
            res=(res+(val1-val2)*i)%MOD;
        }
    }
    
    ll num=((n-2)*(n-1))/2;
    rng(i,0,num-1) res=(res*m)%MOD;
    // res=(res*(n-1))%MOD;
    cout<<(res+MOD)%MOD<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

