
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

#define N 5030
#define MOD 998244353
#define INF 1000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];
ll DP[N][N], psum[N][N], tsum[N][N];
ll sDP[N], stsum[N];

void Solve(){
    ll n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) fill(DP[i], DP[i]+5001,0);
    rng(i,0,n-1) fill(psum[i], psum[i]+5001,0);
    rng(i,0,n-1) fill(tsum[i], tsum[i]+5001,0);
    DP[0][0]=1, psum[0][0]=0, tsum[0][0]=0;
    DP[0][datas[0]]=1, psum[0][datas[0]]=datas[0], tsum[0][datas[0]]=(datas[0]+1)/2;
    
    rng(i,1,n-1){
        rng(j,0,5000){
            DP[i][j]=DP[i-1][j];
            psum[i][j]=psum[i-1][j];
            tsum[i][j]=tsum[i-1][j];
        }
        rng(j,0,5000-datas[i]){
            DP[i][j+datas[i]]=(DP[i][j+datas[i]]+DP[i-1][j])%MOD;
            psum[i][j+datas[i]]=(psum[i][j+datas[i]]+psum[i-1][j]+DP[i-1][j]*datas[i])%MOD;
            if(datas[i]%2==1 && j%2==0) tsum[i][j+datas[i]]=(tsum[i][j+datas[i]]+tsum[i-1][j]+DP[i-1][j]*(1+datas[i]/2))%MOD;
            else tsum[i][j+datas[i]]=(tsum[i][j+datas[i]]+tsum[i-1][j]+DP[i-1][j]*(datas[i]/2))%MOD;
        }
    }

    // cout<<"DP psum tsum\n";
    // rng(i,0,8){
    //     cout<<DP[n-1][i]<<' '<<psum[n-1][i]<<' '<<tsum[n-1][i]<<'\n';
    // }
    // cout<<'\n';

    rng(i,0,5000) sDP[i]=((i==0?0:sDP[i-1])+DP[n-1][i])%MOD;
    rng(i,0,5000) stsum[i]=((i==0?0:stsum[i-1])+tsum[n-1][i])%MOD;
    ll tot=stsum[5000];
    rng(i,0,n-1){
        ll num=sDP[datas[i]-1];
        ll plus=datas[i]*num%MOD;
        ll minus=0;
        if(datas[i]%2==0){
            minus=(stsum[datas[i]-1]+num*datas[i]/2)%MOD;
        }
        else{
            rng(j,0,datas[i]-1){
                if(j%2==0) minus=(minus+tsum[n-1][j]+DP[n-1][j]*(datas[i]/2+1))%MOD;
                else minus=(minus+tsum[n-1][j]+DP[n-1][j]*(datas[i]/2))%MOD;
            }
        }
        tot=(tot-minus+plus)%MOD;   
    }
    cout<<(tot+MOD)%MOD<<'\n';

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

