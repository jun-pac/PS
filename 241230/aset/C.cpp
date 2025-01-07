
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N];
ll sum[N];
set<ll> st;

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1)cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    int t_idx=0;
    rng(i,1,n-1){
        if(datas[i]!=-1 && datas[i]!=1){
            t_idx=i;
            break;
        }
    }
    // 포함하지 않는 경우
    ll mn=0, mx=0;
    ll curmn=0, curmx=0;
    rng(i,0,t_idx-1){
        mx=max(mx,sum[i]-curmn);
        mn=min(mn,sum[i]-curmx);
        curmn=min(curmn,sum[i]);
        curmx=max(curmx,sum[i]);
    }
    curmn=sum[t_idx], curmx=sum[t_idx];
    rng(i,t_idx+1,n-1){
        mx=max(mx,sum[i]-curmn);
        mn=min(mn,sum[i]-curmx);
        curmn=min(curmn,sum[i]);
        curmx=max(curmx,sum[i]);
    }

    // 포함하는 경우
    ll rmx=0, rmn=0, lmx=0, lmn=0;
    gnr(i,t_idx-1,0){ // [i,t_idx-1]구간
        lmx=max(lmx,sum[t_idx-1]-(i==0?0:sum[i-1]));
        lmn=min(lmn,sum[t_idx-1]-(i==0?0:sum[i-1]));
    }
    rng(i,t_idx+1,n-1){ // [t_idx+1,i]구간
        rmx=max(rmx,sum[i]-sum[t_idx]);
        rmn=min(rmn,sum[i]-sum[t_idx]);
    }
    ll dmx=rmx+lmx+datas[t_idx];
    ll dmn=rmn+lmn+datas[t_idx];
    // [dmn, dmx]
    if(dmx<mn){
        cout<<dmx+mx-mn-dmn+2<<'\n';
        rng(i,dmn,dmx) cout<<i<<' ';
        rng(i,mn,mx) cout<<i<<' ';
        cout<<'\n';
    }
    else if(dmn>mx){
        cout<<dmx+mx-mn-dmn+2<<'\n';
        rng(i,mn,mx) cout<<i<<' ';
        rng(i,dmn,dmx) cout<<i<<' ';
        cout<<'\n';
    }
    else{
        mx=max(mx,dmx);
        mn=min(mn,dmn);
        cout<<mx-mn+1<<'\n';
        rng(i,mn,mx) cout<<i<<' ';
        cout<<'\n';
    }
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

