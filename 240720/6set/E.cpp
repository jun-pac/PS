
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
//__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))
ll datas[100];
ll ans[100];
ll DP[100][100][100]; // DP[i][j][k] i번째 idx로 시작하는, 
// 다음 원소가 datas[j]-datas[i]이고 길이가 k+1인 애들의 개수 
// 당연히 j>i여야 의미가 있다.

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    if(n==1){
        cout<<1<<'\n';
        return;
    }
    fill(ans,ans+n,0);
    ans[0]=n;
    ans[1]=(n*(n-1))/2;
    gnr(i,n-1,0){
        rng(j,i+1,n-1){
            rng(k,0,n-j-1){
                DP[i][j][k+1]=0;
                if(k==0) DP[i][j][1]=1;
                else{
                    ll temp=0;
                    rng(nnext,j+1,n-1){
                        if(datas[nnext]-datas[j]==datas[j]-datas[i]) temp+=DP[j][nnext][k];
                    }
                    DP[i][j][k+1]=temp%MOD;
                }
            }
        }
    }
    rng(k,2,n-1){
        ll res=0;
        rng(i,0,n-1-k){
            rng(j,i+1,n-1){
                res=(res+DP[i][j][k])%MOD;
            }
        }
        ans[k]=(res+MOD)%MOD;
    }
    rng(i,0,n-1) cout<<ans[i]<<' ';
    cout<<'\n';

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

