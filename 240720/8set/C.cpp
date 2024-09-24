
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
ll DP[N];

void Solve(){
    ll n,x;
    cin>>n>>x;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    DP[n-1]=(datas[n-1]>x?1:0);

    ll res=0;
    gnr(i,n-2,0){
        if(sum[n-1]-(i==0?0:sum[i-1])<=x) DP[i]=0;
        else{
            int l=i,r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(sum[mid]-(i==0?0:sum[i-1])>x) r=mid;
                else l=mid+1;
            }
            // l=n-1이면 문제가 됨.
            // [i,l]까지 더하는거임
            DP[i]=1+(l==n-1?0:DP[l+1]);
        }
    }
    res=(n*(n+1))/2;
    rng(i,0,n-1)res-=DP[i];
    cout<<res<<'\n';
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

