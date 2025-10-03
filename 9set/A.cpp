
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

ll datas[N];
ll sum[N]; 
int ans[N];

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    ll tot=0;
    

    ans[0]=(sum[(n+1)/2-1] > 0? 1: 0);

    rng(i,1,n-1){
        ll mn=0, mnans;
        if(ans[i-1]+1 <= n-i){
            mn=0;
            mnans = ans[i-1]+1;
        }
        ll temp1;
        if(ans[i-1] <= n-i){
            ll t=(n-i-ans[i-1])/2;
            temp1=sum[i+t]-sum[i-1];
            if(temp1<mn) mn=temp1, mnans=ans[i-1];
        }
        if(ans[i-1] > 0){
            ll t=(n-i-(ans[i-1]-1))/2;
            ll temp=sum[i+t]-sum[i-1]+temp1;
            if(temp<mn) mn=temp, mnans=ans[i-1]-1;
        }
        ans[i]=mnans;
    }    
    rng(i,0,n-1) tot+=ans[i]*datas[i];
    cout<<tot<<'\n';
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

