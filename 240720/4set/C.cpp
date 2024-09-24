
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

ll datas[3][N];
ll sum[3][N];
int n;
int ans[6];
ll tot=0;

bool check(int a, int b, int c){
    int l=0, r=n-1;
    while(l<n){
        if(sum[a][l]>=cediv(tot,3)) break;
        l++;
    }
    while(r>=0){
        if(sum[c][n-1]-(r==0?0:sum[c][r-1])>=cediv(tot,3)) break;
        r--;
    }
    if(r-1>=l+1 && sum[b][r-1]-sum[b][l]>=cediv(tot,3)){
        ans[2*a]=0;
        ans[2*a+1]=l;
        ans[2*c]=r;
        ans[2*c+1]=n-1;
        ans[2*b]=l+1;
        ans[2*b+1]=r-1;
        return 1;
    }   
    else return 0;
    
}

void Solve(){
    cin>>n;
    rng(j,0,2){
        rng(i,0,n-1) cin>>datas[j][i];
    }
    rng(j,0,2){
        rng(i,0,n-1) sum[j][i]=(i==0?0:sum[j][i-1])+datas[j][i];
    }
    tot=sum[0][n-1];
    //assert(sum[0][n-1]==sum[1][n-1] && sum[1][n-1]==sum[2][n-1]);
    rng(i,0,2){
        rng(j,0,2){
            if(i==j) continue;
            int k=3-i-j;
            if(check(i,j,k)){
                rng(uuu,0,5) cout<<ans[uuu]+1<<' ';
                cout<<'\n';
                return;
            }
        }
    }
    cout<<-1<<'\n';
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

