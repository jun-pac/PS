
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
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

int rdp[N], ldp[N];
ll datas[N];
ll sum[N];

void Solve(){
    ll n,m,v;
    cin>>n>>m>>v;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    // ldp : v이상 가능한 개수
    rng(i,0,n-1){
        if(sum[i]<v) ldp[i]=0;
        else{
            int l=0, r=i;
            while(l<r){
                int mid=(l+r+1)>>1;
                if(sum[i]-(mid==0?0:sum[mid-1]) >= v) l=mid;
                else r=mid-1;
            }
            ldp[i]=1+(l==0?0:ldp[l-1]);
        }
    }
    // rdp
    gnr(i,n-1,0){
        if(sum[n-1]-(i==0?0:sum[i-1])<v) rdp[i]=0;
        else{
            int l=i, r=n-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(sum[mid]-(i==0?0:sum[i-1])>=v) r=mid;
                else l=mid+1;
            }
            rdp[i]=1+(l==n-1?0:rdp[l+1]);
        }
    }
    
    ll mx=-1;
    if(ldp[n-1]>=m){
        rng(i,0,n-1){
            if(ldp[i]>=m) mx=max(mx,sum[n-1]-sum[i]);
        }
    }
    if(rdp[0]>=m){
        rng(i,0,n-1){
            if(rdp[i]>=m) mx=max(mx,(i==0?0:sum[i-1]));
        }
    }
    rng(i,1,n-1){
        // i부터는 우측으로 쓴다.
        if(rdp[i]>=m) mx=max(mx,sum[i-1]);
        else if(rdp[i]+ldp[i-1]<m) continue;
        else{
            int l=0, r=i-1;
            while(l<r){
                int mid=(l+r)>>1;
                if(ldp[mid]+rdp[i]>=m) r=mid;
                else l=mid+1;
            }
            mx=max(mx,sum[i-1]-sum[l]);
        }
    }
    cout<<mx<<'\n';
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

