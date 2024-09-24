
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

int datas[N], cur[N];
vc<int> tank[N];

void Solve(){
    int n,mx=0;
    cin>>n;
    rng(i,0,n-1){
        cin>>datas[i];
        mx=max(mx,datas[i]);
    }
    rng(i,0,n-1){
        cur[i]=datas[i];
        if(cur[i]!=1) tank[cediv(datas[i],cur[i]-1)].pb(i);
    }
    ll res=0;
    cur[n]=0;
    rng(i,1,n) res+=max(cur[i-1]-cur[i],0); 
    cout<<res<<' ';
    rng(i,2,mx){
        for(int idx : tank[i]){
            res-=(idx==0?0:max(cur[idx-1]-cur[idx],0))+max(cur[idx]-cur[idx+1],0);
            cur[idx]=cediv(datas[idx],i);
            res+=(idx==0?0:max(cur[idx-1]-cur[idx],0))+max(cur[idx]-cur[idx+1],0);
            if(cur[idx]!=1) tank[cediv(datas[idx],cur[idx]-1)].pb(idx);
        }
        cout<<res<<' ';
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        Solve();
    }
    return 0;
}

