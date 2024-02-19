
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 

ll as[N], bs[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>as[i];
    rng(i,0,n-1) cin>>bs[i];
    ll bsum=0;
    ll asum=0;
    ll mxa=0, mxb=0;
    rng(i,0,n-1) if(as[i]!=0) mxa=i;
    rng(i,0,n-1) if(bs[i]!=0) mxb=i;
    rng(i,0,n-1) asum+=as[i];
    rng(i,0,n-1) bsum+=bs[i];
    if(asum>bsum) bs[0]+=asum-bsum;
    else as[0]+=bsum-asum;
    ll tot=0, res=0;
    bool tenflag=0;
    rng(i,0,n-1){
        if(tot>0 && as[i]>0){
            tenflag=1;
        }
        if(as[i]-min(tot+bs[n-1-i],as[i])>0 && res>0) tenflag=1;
        res+=min(tot+bs[n-1-i],as[i]);
        tot=tot+bs[n-1-i]-min(tot+bs[n-1-i],as[i]);
    }

    if(res==0 || (mxa+mxb)<n) cout<<0<<'\n';
    else if(tenflag) cout<<res<<'\n';
    else cout<<res-1<<'\n';
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

