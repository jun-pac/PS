
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
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

#define MOD 998244353

ll val[300]; // 맞았을 때 score
ll times[300]; // 걸리는 시간
ll DP[300001]; // 앞 DP
ll sum[300];
ll pow2[300];

void Solve(){
    int n,tot; // sum(time) <= total_time;
    cin>>n>>tot;
    rng(i,0,n-1) cin>>val[i];
    rng(i,0,n-1) cin>>times[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+times[i];
    rng(i,0,n) pow2[i]=(i==0?1:pow2[i-1]*2)%MOD;
    //rng(i,0,n-1) cout<<i<<' '<<pow2[i]<<'\n';

    ll res_vis=0;
    fill(DP,DP+tot+1,0);
    DP[0]=1;
    rng(i,0,n-1){
        // times[i]까지 고려한 경우의 수
        ll temp=0;
        rng(j,0,tot-times[i]) temp=(temp+DP[j])%MOD;
        //cout<<"number "<<temp<<'\n';
        res_vis=(res_vis+temp*val[i]%MOD*pow2[n-1-i]%MOD)%MOD;

        gnr(j,tot-times[i],0){
            DP[j+times[i]]=(DP[j+times[i]]+DP[j])%MOD;
        }
        //DP[times[i]]++;
    }

    ll res_invis=0;
    fill(DP,DP+tot+1,0);
    DP[0]=1;
    gnr(i,n-1,0){
        // times[i]까지 고려한 경우의 수
        ll temp=0;
        rng(j,0,tot-(i==0?0:sum[i-1])-times[i]) temp=(temp+DP[j])%MOD;
        //cout<<"number2 "<<temp<<'\n';
        res_invis=(res_invis+temp*val[i]%MOD*pow2[i]%MOD)%MOD;

        gnr(j,tot-times[i],0){
            DP[j+times[i]]=(DP[j+times[i]]+DP[j])%MOD;
        }
        //DP[times[i]]++;        
    }

    cout<<((res_vis+res_invis)%MOD+MOD)%MOD<<'\n';
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

