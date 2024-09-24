
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

ll a[N], b[N], ans[N];
void Solve(){
    ll n,m;
    cin>>n>>m;
    rng(i,0,n+m){
        cin>>a[i];
    }
    rng(i,0,n+m){
        cin>>b[i];
    }
    if(n==0){
        ll bsum=0;
        rng(i,0,n+m) bsum+=b[i];
        rng(i,0,n+m) cout<<bsum-b[i]<<' ';
        cout<<'\n';
        return;
    }
    else if(m==0){
        ll asum=0;
        rng(i,0,n+m) asum+=a[i];
        rng(i,0,n+m) cout<<asum-a[i]<<' ';
        cout<<'\n';
        return;
    }
    ll acnt=0, bcnt=0;
    ll asum=0, bsum=0;
    ll aend=-1, bend=-1;
    rng(i,0,n+m-1){
        if(a[i]>b[i]){
            if(acnt<n){
                asum+=a[i];
                acnt++;
                if(acnt==n) aend=i;
            }
            else{
                bsum+=b[i];
                bcnt++;
                if(bcnt==m) bend=i;
            }
        }
        else{
            if(bcnt<m){
                bsum+=b[i];
                bcnt++;
                if(bcnt==m) bend=i;
            }
            else{
                asum+=a[i];
                acnt++;
                if(acnt==n) aend=i;
            }
        }
    }
    assert(acnt==n && bcnt==m && (aend==n+m-1 || bend==n+m-1) && (aend!=bend));
    ans[n+m]=asum+bsum;

    if(aend<bend){
        int nexta=n+m;
        rng(i,aend+1,n+m-1){
            if(a[i]>b[i]){
                nexta=i;
                break;
            }
        }
        rng(i,0,n+m-1){
            if(a[i]>b[i] && i<=aend){
                ans[i]=asum+bsum-a[i]-b[nexta]+a[nexta]+b[n+m];
            }
            else{
                ans[i]=asum+bsum-b[i]+b[n+m];
            }
        }
    }
    else{
        //cout<<'h'<<'\n';
        int nextb=n+m;
        rng(i,bend+1,n+m-1){
            if(a[i]<b[i]){
                nextb=i;
                break;
            }
        }
        rng(i,0,n+m-1){
            if(a[i]<b[i] && i<=bend){
                ans[i]=asum+bsum-b[i]-a[nextb]+b[nextb]+a[n+m];
            }
            else{
                ans[i]=asum+bsum-a[i]+a[n+m];
            }
        }
    }
    

    rng(i,0,n+m) cout<<ans[i]<<' ';
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

