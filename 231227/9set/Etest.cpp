
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

#define N 100030
#define MOD 998244353
#define INF 1000000007 

vc<pll> datas[N]; // 각 multiset의 정보들. 
pll lr[N];
ll sum[N];

map<ll,ll> idx;
vc<pll> fuck[N]; // idx[i]로 접근하면 datas[a][b]에 접근할 수 있는 a,b들을 준다.

void Solve(){
    int m; // # of multiset
    m=100000;
    rng(i,0,m-1) datas[i].clear();
    ll cnt=0;
    idx.clear();

    rng(i,0,m-1){
        ll n,x;
        n=1;
        if(i%2==0 && i<5) lr[i]={999999999999,1000000000000};
        else lr[i]={1000000000000,1000000000000};

        rng(j,0,n-1){
            x=100000000000000000-i;
            if(idx[x]==0){
                cnt++;
                idx[x]=cnt;
                fuck[cnt].clear();
            }
            fuck[idx[x]].pb({i,j});
            datas[i].pb({x,0});
        }
        //rng(j,0,n-1) cin>>datas[i][j].se;
        datas[i][0].se=1000000000000;
        sum[i]=0;
        rng(j,0,n-1) sum[i]+=datas[i][j].se;
    }

    ll lsum=0, rsum=0, mn=1e18;
    rng(i,0,m-1) lsum+=lr[i].fi, rsum+=lr[i].se;
    if(rsum-lsum+1>cnt){
        cout<<0<<'\n';
        return;
    }

    for(ll cursum=lsum; cursum<=rsum; cursum++){
        cout<<"cursum "<<cursum<<'\n';
        if(idx[cursum]==0){
            mn=0;
            break;
        }
        ll anti=0; // rsum-cursum만큼은 제거를 할 수 있음.
        ll mx_del=0;
        for(auto next : fuck[idx[cursum]]){
            int i=next.fi, j=next.se;
            // sum[i], lr[i].se (r), lr[j].fi (l), datas[i][j].se (cursum의 개수) 
            anti+=max(0LL, lr[i].se-(sum[i]-datas[i][j].se));
            mx_del+=max(0LL, min(lr[i].se-lr[i].fi, lr[i].se-(sum[i]-datas[i][j].se)));
        }
        cout<<anti<<' '<<mx_del<<endl;
        anti=max(0LL,anti-min(rsum-cursum,mx_del));
        mn=min(mn,anti);
    }
    cout<<mn<<'\n';
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

