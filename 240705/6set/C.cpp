
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

ll datas[N], sum[N];
ll DP[N], mx[N];

void Solve(){
    ll n,l,r;
    cin>>n>>l>>r;
    rng(i,0,n-1){
        cin>>datas[i];
    }
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    DP[0]=(datas[0]>=l && datas[0]<=r?1:0);
    mx[0]=DP[0];
    rng(i,1,n-1){
        DP[i]=mx[i-1];
        if(datas[i]<=r){
            int s=0, e=i;
            while(s<e){
                int mid=(s+e+1)>>1;
                if(sum[i]-(mid==0?0:sum[mid-1]) >= l ) s=mid;
                else e=mid-1;
            }
            // [s,e] inclusive, l이상 중 가장 작은 것을 찾으면 됨
            if(l<=sum[i]-(s==0?0:sum[s-1]) && r>=sum[i]-(s==0?0:sum[s-1])) DP[i]=max(DP[i],(s==0?0:mx[s-1])+1);
        }
        mx[i]=max(mx[i-1],DP[i]);
        //cout<<"idx "<<i<<' '<<DP[i]<<'\n';
    }

    cout<<mx[n-1]<<'\n';
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

