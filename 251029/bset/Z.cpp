
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
pair<ll,ll> datas[N]; // Vertices // Convex hull algorithm never permute initial vertices.

inline bool CCW(const pair<ll,ll>& a, const pair<ll,ll>& b, const pair<ll,ll>& c){
    return (b.fi-a.fi)*(c.se-a.se)-(b.se-a.se)*(c.fi-a.fi)>0;
}

pll rightend[N], leftend[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i].fi>>datas[i].se;
    sort(datas,datas+n);

    pii st[N]; 
    int cur=0, st_cnt=0; 
    while(cur<n){
        while(st_cnt>=2 && !CCW(st[st_cnt-2],st[st_cnt-1],datas[cur])) st_cnt--;
        if(cur>=0) leftend[cur]=st[st_cnt-1];
        st[st_cnt++]=datas[cur++];
    }
    // rng(i,1,n-1) cout<<"left "<<i<<" : "<<leftend[i].fi<<' '<<leftend[i].se<<'\n';

    cur=n-1, st_cnt=0; 
    while(cur>=0){
        while(st_cnt>=2 && CCW(st[st_cnt-2],st[st_cnt-1],datas[cur])) st_cnt--;
        if(cur<n-1) rightend[cur]=st[st_cnt-1];
        st[st_cnt++]=datas[cur--];
    }
    // rng(i,0,n-2) cout<<"right "<<i<<" : "<<rightend[i].fi<<' '<<rightend[i].se<<'\n';

    double mx=0;
    rng(i,1,n-2){
        double y=datas[i].se;
        double x=datas[i].fi;
        double xr=rightend[i].fi, yr=rightend[i].se;
        assert(y>yr);
        double xright=x+(xr-x)/(y-yr)*y;

        double xl=leftend[i].fi, yl=leftend[i].se;
        assert(y>yl);
        double xleft=x-(x-xl)/(y-yl)*y;
        // cout<<i<<' '<<x<<' '<<y<<' '<<xright<<' '<<xleft<<' '<<(xright-xleft)*y/2<<'\n';
        mx=max(mx,(xright-xleft)*y/2);
    }
    cout<<fixed;
    cout.precision(12);
    cout<<mx<<'\n';
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

