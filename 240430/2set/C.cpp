
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

ll datas[N], dur[N];
ll even_dur[N], even_sum[N];

void Solve(){
    ll tot,n,y;
    cin>>tot>>n>>y;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) datas[i]--;
    sort(datas,datas+n);
    ll ecnt=0;

    rng(i,0,n-2){
        dur[i]=datas[i+1]-datas[i];
        if(dur[i]%2==0) even_dur[ecnt++]=(dur[i]-1)/2;
    }
    dur[n-1]=(datas[0]+tot-datas[n-1]);
    if(dur[n-1]%2==0) even_dur[ecnt++]=(dur[n-1]-1)/2;

    sort(even_dur,even_dur+ecnt);
    rng(i,0,ecnt-1) even_sum[i]=(i==0?0:even_sum[i-1])+even_dur[i];    

    ll cnt=0;
    ll even_pos=0;
    ll odd_pos=0;
    rng(i,0,n-1){
        if(dur[i]%2==0) even_pos+=(dur[i]-1)/2;
        else odd_pos+=(dur[i]-1)/2;
    }

    if(y>=odd_pos+even_pos){
        cnt=even_pos+odd_pos+ecnt-(y-odd_pos-even_pos);
    }
    else{
        if(y>=even_pos) cnt=y+ecnt;
        else{
            assert(even_sum[ecnt-1]==even_pos);
            cnt=upper_bound(even_sum,even_sum+ecnt,y)-even_sum;
            cnt+=y;
        }
    }

    cout<<n+y-2+cnt<<'\n';
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

