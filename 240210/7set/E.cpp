
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

int initval[N], ans[N];
ll sum[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    int cur=1;
    rng(i,0,k-1){
        initval[i]=cur;
        cur+=(n-i-1)/k+1;
        if(i%2==0){
            int j=0;
            ans[j*k+i]=initval[i];
            j++;
            while(j*k+i<n){
                ans[j*k+i]=ans[(j-1)*k+i]+1;
                j++;
            }
        }
        else{
            int j=(n-i-1)/k;
            ans[j*k+i]=initval[i];
            j--;
            while(j*k+i>=0){
                ans[j*k+i]=ans[(j+1)*k+i]+1;
                j--;
            }
        }
    }
    rng(i,0,n-1) cout<<ans[i]<<' ';
    cout<<'\n';
    
    
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+ans[i];
    ll mx=sum[k-1], mn=sum[k-1];
    rng(i,0,n-k){
        ll val=sum[i+k-1]-(i==0?0:sum[i-1]);
        mx=max(mx,val);
        mn=min(mn,val);
    }
    //cout<<mx<<' '<<mn<<'\n';
    assert(mx-mn<=1);
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

