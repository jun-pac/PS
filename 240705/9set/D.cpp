
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
int DP[5005][5005];
int datas[5005];
int cnt[5005]; // 이건 새로운 idx에서
int sum[5005];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    sort(datas,datas+n);
    int idx=0;
    int last_idx=0;
    int last=datas[0];
    rng(i,0,n-1){
        if(datas[i]!=last){
            cnt[idx++]=i-last_idx;
            last=datas[i];
            last_idx=i;
        }
    }
    cnt[idx++]=n-last_idx;

    rng(i,0,idx) fill(DP[i],DP[i]+idx+1,INF);
    rng(i,0,idx) DP[i][0]=0; // [i][j]가 i번째 원소까지 j개의 block을 내가 지워버리겠다는거니까
    int mx=0;
    rng(i,1,idx-1){
        rng(j,1,i){
            DP[i][j]=DP[i-1][j];
            if(cnt[i]+DP[i-1][j-1]<=i+1-j){
                DP[i][j]=min(DP[i][j],cnt[i]+DP[i-1][j-1]);
                //cout<<"Here\n";
            }
            //cout<<i<<' '<<j<<' '<<DP[i][j]<<" | "<<cnt[i]<<' '<<DP[i-1][j-1]<<' '<<i+1-j<<'\n';
        }
    }
    int res=idx;
    rng(i,0,idx){
        if(DP[idx-1][i]<INF){
            res=min(res,idx-i);
        }
    }

    cout<<res<<'\n';
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

