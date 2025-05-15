
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

#define N 200030
#define MOD 998244353
#define INF 1000000007 
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

ll datas[N][3];
ll vval[3][N], cal[3][N];
ll m[3], sum_cal[3];
ll DP[3][5005][5005];
ll x;

bool check(ll mn_vita){
    ll mn_cal=0;
    rng(k,0,2){
        if(m[k]==0 || DP[k][m[k]-1][min(x,sum_cal[k])]<mn_vita) return false;
        mn_cal=mn_cal+(lower_bound(DP[k][m[k]-1],DP[k][m[k]-1]+min(x,sum_cal[k])+1,mn_vita)-DP[k][m[k]-1]);
    }
    return mn_cal<=x;
}

void Solve(){
    ll n;
    cin>>n>>x; // x: limit of vita
    fill(m,m+3,0);
    fill(sum_cal,sum_cal+3,0);

    rng(i,0,n-1){
        rng(j,0,2) cin>>datas[i][j];
        datas[i][0]--;
        int typ=datas[i][0];
        vval[typ][m[typ]]=datas[i][1];
        cal[typ][m[typ]]=datas[i][2];
        sum_cal[typ]+=datas[i][2];
        m[typ]++;
        // cin>>vtype[i]>>vval[i]>>cal[i];
        // vtype[i]--;
    }
    // 이분탐색, 셋 모두 mid이상의 vita를 가지도록 하는 게 가능한지?
    // 가능하면 그 값을 키우는거죠

    rng(k,0,2){
        fill(DP[k][0],DP[k][0]+min(x,sum_cal[k])+1,0);
        if(m[k]>=1 && cal[k][0]<=min(x,sum_cal[k])) fill(DP[k][0]+cal[k][0],DP[k][0]+min(x,sum_cal[k])+1,vval[k][0]);
        rng(i,1,m[k]-1){
            rng(j,0,min(x,sum_cal[k])){
                DP[k][i][j]=DP[k][i-1][j];
                if(j>=cal[k][i]) DP[k][i][j]=max(DP[k][i][j],DP[k][i-1][j-cal[k][i]]+vval[k][i]);
            }
        }
    }

    ll l=0, r=INF;
    while(l<r){
        ll mid=(l+r+1)>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<'\n';
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

