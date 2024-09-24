
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

string aa[505], bb[505];
int a[505][505], b[505][505];

void Solve(){
    int n,m;
    cin>>n>>m;
    int asum=0, bsum=0;
    rng(i,0,n-1) cin>>aa[i];
    rng(i,0,n-1){
        rng(j,0,m-1){
            asum+=(aa[i][j]-'0');
            a[i][j]=aa[i][j]-'0';
        }
    }
    rng(i,0,n-1) cin>>bb[i];
    rng(i,0,n-1){
        rng(j,0,m-1){
            bsum+=(bb[i][j]-'0');
            b[i][j]=bb[i][j]-'0';
        }
    }

    rng(i,0,n-2){
        rng(j,0,m-2){
            if((a[i][j]+1)%3==b[i][j]){
                a[i][j]=(a[i][j]+1)%3;
                a[i+1][j]=(a[i+1][j]+2)%3;
                a[i][j+1]=(a[i][j+1]+2)%3;
                a[i+1][j+1]=(a[i+1][j+1]+1)%3;
            }
            else if((a[i][j]+2)%3==b[i][j]){
                a[i][j]=(a[i][j]+2)%3;
                a[i+1][j]=(a[i+1][j]+1)%3;
                a[i][j+1]=(a[i][j+1]+1)%3;
                a[i+1][j+1]=(a[i+1][j+1]+2)%3;
            }
        }
    }
    bool flag=1;
    rng(i,0,n-1) if(abs(a[i][m-1]-b[i][m-1])%3!=0) flag=0;
    rng(j,0,m-1) if(abs(a[n-1][j]-b[n-1][j])%3!=0) flag=0;
    cout<<(flag?"YES\n":"NO\n");
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

