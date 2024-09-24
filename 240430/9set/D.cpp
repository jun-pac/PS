
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

ll ap[N], bp[N];
pll ss[N];
priority_queue<ll> mq;

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>ap[i];
    rng(i,0,n-1) cin>>bp[i];
    rng(i,0,n-1) ss[i]={ap[i],bp[i]};
    if(k==n){
        cout<<0<<'\n';
        return;
    }
    while(!mq.empty()) mq.pop();
    rng(i,0,n-1) ss[i]={bp[i],ap[i]};
    sort(ss,ss+n);
    reverse(ss,ss+n);
    ll rsum=0; // b-aÀÇ sum
    ll lsum=0; // aÀÇ sum
    ll mx=0; // maximum profit : rsum-lsum
    rng(i,k,n-1){
        rsum+=max(0LL,ss[i].fi-ss[i].se);
    }
    rng(i,0,k-1){
        mq.push(ss[i].se);
        lsum+=ss[i].se;
    }
    mx=max(mx,rsum-lsum);
    rng(i,k,n-1){
        rsum-=max(0LL,ss[i].fi-ss[i].se);
        lsum+=ss[i].se;
        mq.push(ss[i].se);
        lsum-=mq.top();
        mq.pop();
        
        mx=max(mx,rsum-lsum);
    }
    cout<<mx<<'\n';

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

