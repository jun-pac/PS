
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
ll INF=(1LL<<32);

ll a[N], b[11];
pll andb[1<<10]; // {and b, num b}
ll datas[N][11]; // 각 idx에 대해서 min 결과 using cnt number of bs.
ll deltas[1000010];

void Solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    rng(i,0,n-1) cin>>a[i];
    rng(i,0,m-1) cin>>b[i];
    rng(j,0,(1<<m)-1){
        ll cnt=0, val=(1<<30)-1;
        rng(tt,0,m-1) if((1<<tt) & j) cnt++;
        rng(tt,0,m-1) if((1<<tt) & j) val=val&b[tt];
        andb[j]={val,cnt};
    }
    // ll vv=b[0];
    // rng(i,0,m-1) vv=vv&b[i];
    // cout<<"abs "<<vv<<'\n';
    // rng(i,0,n-1) cout<<(vv&a[i])<<'\n';
    rng(i,0,n-1){
        fill(datas[i], datas[i]+m+1, INF);
        rng(j,0,(1<<m)-1){
            // if(j==(1<<m)-1) cout<<"Ds "<<andb[j].se<<' '<<andb[j].fi<<'\n';
            datas[i][andb[j].se]=min(datas[i][andb[j].se],a[i]&andb[j].fi);
        }
        // rng(j,0,m) cout<<"debug "<<j<<' '<<datas[i][j]<<'\n';
    }
    rng(i,0,n-1){
        rng(j,1,m){
            deltas[i*m+j-1]=datas[i][j]-datas[i][j-1]; // negs
        }
    }
    sort(deltas,deltas+n*m);
    ll sum=0;
    
    rng(i,0,n-1) sum+=a[i];
    // cout<<"sums "<<sum<<'\n';
    rng(i,0,k-1) sum+=deltas[i];
    cout<<sum<<'\n';
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

