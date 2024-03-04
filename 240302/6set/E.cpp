
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

ll datas[N], sum[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    int q;
    cin>>q;
    rng(i,0,q-1){
        ll x,u;
        cin>>x>>u;
        x--;
        // sum[i]-sum[x-1]이 최대한 u에 가까운
        int pos=upper_bound(sum,sum+n,(x==0?0:sum[x-1])+u)-sum; // sum[x-1]+u보다 큰 곳
        if(pos==n){
            ll num=sum[n-1]-(x==0?0:sum[x-1]);
            cout<<n<<' ';
        }
        else if(pos==x){
            cout<<pos+1<<' ';
        }
        else{
            ll num=sum[pos]-(x==0?0:sum[x-1]);
            ll res1=num*u-(num*(num-1))/2;
            num=(pos==0?0:sum[pos-1])-(x==0?0:sum[x-1]);
            ll res2=num*u-(num*(num-1))/2;
            cout<<(res1>res2?pos+1:pos)<<' ';
        }
    }
    cout<<'\n';
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

