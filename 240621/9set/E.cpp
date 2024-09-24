
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
ll sum[N];
ll ans[N];

void Solve(){
    ll n,c;
    cin>>n>>c;
    rng(i,0,n-1) cin>>datas[i];
    ll mx = datas[0]+c;
    int idx=0;
    rng(i,1,n-1){
        if(datas[i]>mx){
            mx=datas[i];
            idx=i;
        }
    }
    rng(i,0,n-1) sum[i]=(i==0?0:sum[i-1])+datas[i];
    priority_queue<ll> pq;
    ll supp=0, cnt=0;
    gnr(i,n-1,0){
        if(i==idx){
            ans[i]=0;
            pq.push(datas[i]);
        }
        else{
            // delete all before i
            ll cur=sum[i]+c;
            while(!pq.empty() && cur+supp<pq.top()){
                supp=pq.top();
                cnt++;
                pq.pop();  
            }
            ans[i]=i+cnt;
            pq.push(datas[i]);
        }
    }
    rng(i,0,n-1) cout<<ans[i]<<' ';
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

