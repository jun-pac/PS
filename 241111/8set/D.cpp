
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

ll a[N];
ll asum[N], asumsum[N];

ll bseg(ll bnum, ll l, ll r){
    // n-bnum개의 element가 있는 행렬임
    return asumsum[bnum+r]-(bnum+l==0?0:asumsum[bnum+l-1])-(bnum==0?0:asum[bnum-1])*(r-l+1);
}

ll bsum[N];
ll n;

ll get_idx(ll bnum, ll idx){
    return idx-((2*n-bnum+1)*bnum)/2;
}

ll get_block(ll idx){
    ll l=0, r=n-1;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(get_idx(mid,idx)<0) r=mid-1;
        else l=mid;
    }
    return l;
}


void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,n-1) asum[i]=(i==0?0:asum[i-1])+a[i];
    rng(i,0,n-1) asumsum[i]=(i==0?0:asumsum[i-1])+asum[i];
    rng(i,0,n-1) bsum[i]=(i==0?0:bsum[i-1])+bseg(i,0,n-1-i);

    ll q;
    cin>>q;
    rng(i,0,q-1){
        ll l,r;
        cin>>l>>r;
        l--, r--;
        ll lb=get_block(l);
        ll rb=get_block(r);
        //cout<<"lr lb rb: "<<l<<' '<<r<<' '<<lb<<' '<<rb<<' '<<get_idx(lb,l)<<' '<<get_idx(rb,r)<<'\n';
        if(lb==rb){
            cout<<bseg(lb,get_idx(lb,l),get_idx(lb,r))<<'\n';
        }
        else{
            ll res=bseg(lb,get_idx(lb,l),n-1-lb);
            res+=bseg(rb,0,get_idx(rb,r));
            if(rb-lb>1) res+=bsum[rb-1]-bsum[lb];
            cout<<res<<'\n';
        }
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

