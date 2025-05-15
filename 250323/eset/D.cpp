
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
#define MOD 1000000007

ll DP[5001][26][101]; // 26은 이제 그 자신을 포함해서 몇 개의 counterfeit이 나왔는지
ll temp[26][101];
ll sum[5501];

#define MAX_DIGIT 62

// Remember (ak)*(bk)^(-1) === a*b^(-1) === (ak%P)*(bk%P)^(-1) (mod P)
long long ari_inv(long long num){
    // Calculate num^(MOD-2)
    long long res=1, mult=num;
    for(int i=0; i<MAX_DIGIT; i++){
        if((MOD-2)&(1LL<<i)){
            res=(res*mult)%MOD;
        }
        mult=(mult*mult)%MOD;
    }
    return res;
}

void Solve(){
    ll n,l,k;
    cin>>n>>l>>k;
    // assert(k==0);

    rng(i,0,l-1) rng(num,0,k) fill(DP[i][num],DP[i][num]+n,0);

    ll pos=(l*ari_inv(l+k))%MOD;
    ll neg=(k*ari_inv(l+k))%MOD;
    fill(DP[0][1],DP[0][1]+n,0);
    DP[0][0][0]=1;
    fill(DP[0][0][1]+1,DP[0][0][1]+n,0);
    
    
    rng(i,1,l+k-1){ // because we have l keys;
        rng(num,max(0LL,i+1-l),k){
            // num개의 흉악한 원소가 있음
            // 내가 흉악한 원소일 때
            if(num!=0){
                // 확률은 num/(i+1)임 
                // num-1개가 이전에 등장.
                ll p=(num*ari_inv(i+1))%MOD;
                rng(j,0,n-1) DP[i][num][j]=(p*DP[i][num-1][(j-(i+1-num)+n)%n])%MOD;
            }
            // 내가 흉악하지 않을 때. 확률은 (i+1-num)/(i+1)임 
            // i+1-num개의 남은 자물쇠.
            // 
        }
        rng(j,0,n-1) temp[j]=DP[i-1][(j-1+n)%n]+(j==0?1:0);
        rng(j,0,i+1+n-1) sum[j]=((j==0?0:sum[j-1])+temp[j%n])%MOD;
        rng(j,i+1,i+1+n-1) DP[i][j%n]=(sum[j]-sum[j-(i+1)])%MOD*ari_inv(i+1)%MOD;
    }



    rng(i,0,n-1) cout<<(DP[l-1][k][i]+MOD)%MOD<<' ';
    cout<<'\n';
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

