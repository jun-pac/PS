
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

ll DP[2][1<<10];
string s;
// A : 0, B : 1
// (x/(1<<(k-1)))*2+최근 값
// (1<<k)가지가 각각 palindrome인지는 어떻게 확인?
int k;
bool is_pal[1<<10];

void check_pal(){
    rng(i,0,(1<<k)-1){
        bool flag=1;
        rng(j,0,k-1){
            bool a=(i&(1<<j)), b=(i&(1<<(k-1-j)));
            //cout<<i<<' '<<a<<' '<<b<<'\n';
            if(a!=b){
                flag=0;
                break;
            }
        }
        is_pal[i]=flag;
        //cout<<i<<' '<<is_pal[i]<<'\n';
    }
}

void Solve(){
    int n;
    cin>>n>>k;
    cin>>s;
    check_pal();
    rng(i,0,k-2){
        rng(j,0,(1<<(i+1))) DP[i%2][j]=0;
        if(i==0){
            if(s[i]=='A') DP[i%2][0]=1;
            else if(s[i]=='B') DP[i%2][1]=1;
            else{
                DP[i%2][0]=1;
                DP[i%2][1]=1;
            }
        }
        else{
            rng(j,0,(1<<i)){
                if(s[i]=='A') DP[i%2][2*j]=DP[(i+1)%2][j];
                else if(s[i]=='B') DP[i%2][2*j+1]=DP[(i+1)%2][j];
                else{
                    DP[i%2][2*j]+=DP[(i+1)%2][j];
                    DP[i%2][2*j+1]+=DP[(i+1)%2][j];
                }
            }
        }
    }
    ll val=(1<<(k-1));
    rng(i,k-1,n-1){
        rng(j,0,(1<<(k-1))) DP[i%2][j]=0;
        rng(j,0,(1<<(k-1))){
            if(s[i]!='B' && !is_pal[2*j]){
                DP[i%2][(2*j)%val+0]=(DP[i%2][(2*j)%val+0]+DP[(i+1)%2][j])%MOD;
            }
            if(s[i]!='A' && !is_pal[2*j+1]){
                DP[i%2][(2*j)%val+1]=(DP[i%2][(2*j)%val+1]+DP[(i+1)%2][j])%MOD;
            }
        }
    }
    ll res=0;
    rng(j,0,(1<<(k-1))){
        res=(res+DP[(n-1)%2][j])%MOD;
    }
    cout<<(res+MOD)%MOD<<'\n';
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

