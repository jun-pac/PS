
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
#define INF 1000000007000000007 
const long double epsilon=0.0000000000001;
pll xh[N];
pair<double, double> xhd[N];

int n;
bool check_zero(){ // 다 보이면 true
    ll mxa=xh[0].fi, mxb=xh[0].se;
    rng(i,1,n-1){
        ll cura=xh[i].fi, curb=xh[i].se;
        if(mxb>=0 && curb*mxa<=cura*mxb) return false;
        if(mxb<0 && curb<0 && curb*mxa<=cura*mxb) return false;
        mxa=cura;
        mxb=curb;
    }
    return true;
}

bool check(long double h0){ // 다 보이면 true
    long double mxa=xhd[0].fi, mxb=xhd[0].se-h0;
    rng(i,1,n-1){
        long double cura=xhd[i].fi, curb=xhd[i].se-h0;
        if(mxb>=0 && curb<=0) return false;
        if(curb*mxa<=cura*mxb) return false;
        mxa=cura;
        mxb=curb;
    }
    return true;
}

void Solve(){
    cin>>n;
    rng(i,0,n-1) cin>>xh[i].fi>>xh[i].se;
    rng(i,0,n-1) xhd[i]=xh[i];
    
    long double l=0, r=1000000007000000007;
    if(check_zero()){
        cout<<-1<<'\n';
        return;
    }
    while(abs(r-l)>(r+l)*epsilon){
        long double mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }
    cout.precision(15);
    cout<<fixed;
    cout<<l-epsilon<<'\n';
    
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

