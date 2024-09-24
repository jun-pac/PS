
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

ll datas[N];
ll sum[N];
ll p2[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    ll mx=0;
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    mx=-1;
    int idx=-1;
    rng(i,1,n-1){
        if(abs(sum[i-1])+(sum[n-1]-sum[i-1])>mx) idx=i;
        mx=max(mx,abs(sum[i-1])+(sum[n-1]-sum[i-1]));
    }
    if(mx<abs(sum[n-1])) idx=n; // 마지막에 abs
    mx=max(mx,abs(sum[n-1]));
    ll th=sum[idx-1];



    if(sum[idx-1]>=0){
        ll ans=1;
        rng(i,0,n-1){
            if(sum[i]>=0) ans=ans*2%MOD;
        }
        cout<<(ans+MOD)%MOD<<'\n';
    }
    else{
        ll ans1=1;
        rng(i,0,idx-2){
            if(sum[i]>=0) ans1=ans1*2%MOD;
        }
        ll ans2=0;
        rng(i,idx-1,n-1){
            if(sum[i]==th){
                ans2=(ans2+ans1*p2[n-1-i])%MOD;
                //cout<<"plus : "<<i<<' '<<ans1<<' '<<p2[n-1-i]<<'\n';
            }
            else if(sum[i]>=0) ans1=(ans1*2)%MOD;
        }
        cout<<(ans2+MOD)%MOD<<'\n';

    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    cin>>t;
    rng(i,0,200002) p2[i]=(i==0?1:p2[i-1]*2)%MOD;
    while(t--){
        Solve();
    }
    return 0;
}

