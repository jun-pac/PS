
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define cediv(a,b) ((a)%(b)==0?((a)/(b)):((a)/(b))+1)
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define pb push_back
template<class t> using vc=vector<t>;
typedef long long ll;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define N 500030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); 

ll c[N],w[N],csum[N],wsum[N];
vc<ll> wsort[2*N]; // 해당하는 c값에 따른 wsum들을 정렬된 상태로 둘거임 

void Solve(){
    ll n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>c[i];
    rng(i,0,n-1) cin>>w[i];
    rng(i,0,n-1) csum[i]=(i==0?0:csum[i-1])+(c[i]==2?1:-1);
    rng(i,0,n-1) wsum[i]=(i==0?0:wsum[i-1])+(c[i]==2?w[i]:-w[i]);
    rng(i,0,2*n+1) wsort[i].clear();
    wsort[n].push_back(0);
    rng(i,0,n-1){
        wsort[csum[i]+n].pb(wsum[i]);
    }
    rng(i,0,2*n+1) sort(wsort[i].begin(),wsort[i].end());
    ll res=upper_bound(wsort[n].begin(),wsort[n].end(),k)-lower_bound(wsort[n].begin(),wsort[n].end(),-k);
    res--;
    rng(i,0,n-1){
        ll cval=csum[i];
        ll temp=0;
        temp=upper_bound(wsort[cval+n].begin(),wsort[cval+n].end(),wsum[i]+k)-lower_bound(wsort[cval+n].begin(),wsort[cval+n].end(),wsum[i]-k);
        temp-=1;
        res+=temp;
    }
    cout<<res/2<<'\n';
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    rng(i,0,t-1) Solve();
    return 0;
}

