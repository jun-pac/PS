
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
#define INF 10000000000000007 
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

ll datas[N];
ll DP[N][11]; // [idx][i][j] : i는 마지막에 쓴 개수, j는 이때까지 쓴 것. i<=j

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    rng(i,0,n-1) fill(DP[i],DP[i]+k+1,INF);
    rng(idx,0,n-1){
        rng(i,0,min(idx,k)){
            rng(j,0,min(idx-i,k-i)){
                // i+j만큼 사용한 것.
                // 값은 datas[idx-i]
                // 그 이전 값은? idx-i-j-1이하를 말하는 것이다.
                //cout<<"idx i j "<<idx<<' '<<i<<' '<<j<<'\n';
                ll val=(i+j+1)*datas[idx-i];
                if(idx==i+j){
                    DP[idx][i+j]=min(DP[idx][i+j],val);
                }
                else{
                    rng(mu,0,k-i-j){
                        DP[idx][mu+i+j]=min(DP[idx][mu+i+j],DP[idx-i-j-1][mu]+val);
                    }
                }
            }
        }
        // cout<<"IDX : "<<idx<<" | ";
        // rng(i,0,k) cout<<DP[idx][i]<<' ';
        // cout<<'\n';
    }
    ll mn=INF;
    rng(i,0,k){
        //cout<<DP[n-1][i]<<' ';
        mn=min(mn,DP[n-1][i]);
    }
    //cout<<'\n';
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

