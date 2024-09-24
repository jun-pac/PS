
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

ll datas[N];
ll res[N];
bool DFS(ll l, ll r, ll k){
    ll mx=0;
    ll n=(r-l+1);
    if(n==1){
        if(k==0){
            res[l]=l;
            return 1;
        }
        else return 0;
    }
    if(n==2){
        if(k==0){
            res[l]=l;
            res[r]=r;
            return 1;
        }
        else if(k==2){
            res[l]=r;
            res[r]=l;
            return 1;
        }
        else return 0;
    }
    if(k>=2*(n-1)){
        res[l]=r;
        res[r]=l;
        return DFS(l+1, r-1, k-2*(n-1));
    }
    else{
        rng(i,l,r) res[i]=i;
        res[l]=l+k/2;
        res[l+k/2]=l;
        return 1;
    }
}
void Solve(){
    ll n,k;
    cin>>n>>k;
    //cout<<"nk : "<<n<<' '<<k<<'\n';
    if(k%2==1){
        cout<<"No\n";
    }
    else{
        bool flag=DFS(0,n-1,k);
        if(!flag) cout<<"No\n";
        else{
            cout<<"Yes\n";
            rng(i,0,n-1) cout<<res[i]+1<<' ';
            cout<<'\n';
        }
    }
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

