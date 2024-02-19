
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
ll INF=1000000000;

ll datas[N];
ll DP[N];
bool visited[N];
pll sdata[N];

void Solve(){
    int n,k;
    cin>>n>>k;
    rng(i,0,n-1) cin>>datas[i];
    if(k==n){
        cout<<INF<<'\n';
        return;
    }
    else if(n==2){
        if(k==0) cout<<min(datas[0],datas[1])<<'\n';
        if(k==1) cout<<max(datas[0],datas[1])<<'\n';
        return;
    }
    else if(k==0){
        ll res=min(datas[0],datas[1]);
        rng(i,0,n-2) res=max(res,min(datas[i],datas[i+1]));
        ll mn=datas[0];
        rng(i,0,n-1) mn=min(mn,datas[i]);
        res=min(res,2*mn);
        return;
    }
    
    rng(i,0,n-1) sdata[i]={datas[i],i};
    sort(sdata,sdata+n);
    fill(visited,visited+n,0);
    rng(i,0,k-1){
        visited[sdata[i].se]=1;
        datas[sdata[i].se]=INF;
    }
    ll mnk=sdata[k].fi; // k+1¹øÂ° °ª
    bool flag=0;
    rng(i,0,n-2) if(visited[i] && visited[i+1]) flag=1;
    if(flag){
        cout<<min(INF,2*mnk)<<'\n';
    }
    else{
        ll valmn=0;
        rng(i,0,n-2) valmn=max(valmn,min(datas[i],datas[i+1]));
        cout<<max(min(INF,2*sdata[k-1].fi), min(valmn,2*mnk))<<'\n';   
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

