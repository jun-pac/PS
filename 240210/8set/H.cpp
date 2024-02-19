
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

#define N 202
#define MOD 998244353
#define INF 1000000007 

ll DP[101][101]; // [i][j] total down, latest down
ll temp[101][101];
long long fact[N], f_inv[N];

void fill_fact(){
    fact[0]=1;
    for(int i=1; i<N; i++) fact[i]=fact[i-1]*i%MOD;
    fill(f_inv,f_inv+N,1);
    for(int k=0; k<30; k++){
        for(int i=0; i<N; i++){
            f_inv[i]=f_inv[i]*f_inv[i]%MOD;
            if((MOD-2)&(1<<(29-k))) f_inv[i]=f_inv[i]*fact[i]%MOD;
        }
    }
}

long long nCr(int n, int r){
    return ((fact[n]*f_inv[r])%MOD)*f_inv[n-r]%MOD;
}


void Solve(){
    int n,k;
    cin>>n>>k;
    fill_fact();
    rng(i,0,k) fill(DP[i],DP[i]+k+1,0);
    rng(i,0,k) fill(temp[i],temp[i]+k+1,0);

    rng(j,0,k) DP[j][j]=1;
    rng(i,1,n-1){
        rng(i,0,k) fill(temp[i],temp[i]+k+1,0);
        rng(tot,0,k){
            rng(last,0,tot){
                // DP[tot][last]
                rng(pr,0,last-1){
                    temp[tot][last]=(temp[tot][last]+DP[tot-(last-pr)][pr])%MOD;
                }
                rng(pr,last,tot){
                    temp[tot][last]=(temp[tot][last]+DP[tot][pr])%MOD;
                }
            }
        }
        rng(j,0,k) rng(jj,0,k) DP[j][jj]=temp[j][jj];
    }
    ll sum1=0;
    rng(i,0,k) rng(j,0,k) sum1=(sum1+DP[i][j])%MOD;

    ll sum2=0;
    rng(i,0,k-1){
        sum2=(sum2+nCr(n+i-1,i))%MOD;
    }

    sum1-=sum2;
    sum1%=MOD;
    cout<<(sum1+MOD)%MOD<<'\n';

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

