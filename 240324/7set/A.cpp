
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

ll datas[N], sum[N], mx[N], mn[N];

void Solve(){
    ll n,c;
    cin>>n>>c;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    rng(i,0,n-1) mx[i]=max((i==0?0:mx[i-1]),sum[i]);
    rng(i,0,n-1) mn[i]=min((i==0?0:mn[i-1]),sum[i]);
    
    if(c==1){
        cout<<sum[n-1]<<'\n';
    }
    else if(c<1){
        ll cur_mn=0;
        rng(i,0,n-1) cur_mn=min(cur_mn,sum[i]-mx[i]);
        cout<<sum[n-1]+cur_mn*(c-1)<<'\n';
    }
    else{
        ll cur_mx=0;
        rng(i,0,n-1) cur_mx=max(cur_mx,sum[i]-mn[i]);
        cout<<sum[n-1]+cur_mx*(c-1)<<'\n';
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

