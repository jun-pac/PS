
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
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> A[N], B[N];
ll mxa[N], mxb[N];
ll dist[N];
ll d1[N], d2[N];
ll bsum[N];

void DFSA(int idx, int p, int d){
    dist[idx]=d;
    for(auto next: A[idx]){
        if(next!=p){
            DFSA(next, idx, d+1);
        }
    }
}

void DFSB(int idx, int p, int d){
    dist[idx]=d;
    for(auto next: B[idx]){
        if(next!=p){
            DFSB(next, idx, d+1);
        }
    }
}

void Solve(){
    int na;
    cin>>na;
    rng(i,0,na-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        A[a].pb(b);
        A[b].pb(a);
    }
    int nb;
    cin>>nb;
    rng(i,0,nb-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        B[a].pb(b);
        B[b].pb(a);
    }

    int p1, p2, mx=-1;
    // A
    DFSA(0,-1,0);
    mx=-1;
    rng(i,0,na-1){
        if(dist[i]>mx){
            mx=dist[i];
            p1=i;
        }
    }
    DFSA(p1,-1,0);
    mx=-1;
    rng(i,0,na-1){
        if(dist[i]>mx){
            mx=dist[i];
            p2=i;
        }
    }
    rng(i,0,na-1) d1[i]=dist[i];
    DFSA(p2,-1,0);
    rng(i,0,na-1) mxa[i]=max(dist[i],d1[i]);


    // B
    DFSB(0,-1,0);
    mx=-1;
    rng(i,0,nb-1){
        if(dist[i]>mx){
            mx=dist[i];
            p1=i;
        }
    }
    DFSB(p1,-1,0);
    mx=-1;
    rng(i,0,nb-1){
        if(dist[i]>mx){
            mx=dist[i];
            p2=i;
        }
    }
    rng(i,0,nb-1) d1[i]=dist[i];
    DFSB(p2,-1,0);
    rng(i,0,nb-1) mxb[i]=max(dist[i],d1[i]);

    // cout<<"A: ";
    // rng(i,0,na-1) cout<<mxa[i]<<' ';
    // cout<<'\n';

    // cout<<"B: ";
    // rng(i,0,nb-1) cout<<mxb[i]<<' ';
    // cout<<'\n';

    // main
    ll res=0;
    sort(mxa,mxa+na);
    sort(mxb,mxb+nb);
    ll base=max(mxa[na-1],mxb[nb-1]);
    rng(i,0,nb-1){
        bsum[i]=(i==0?0:bsum[i-1])+mxb[i];
    }
    rng(i,0,na-1){
        // base-1-mxa[i] 이상이면 이게 반영된다.
        int pos=lower_bound(mxb,mxb+nb,base-1-mxa[i])-mxb;
        res+=pos*base;
        if(pos!=nb) res+=(bsum[nb-1]-(pos==0?0:bsum[pos-1]))+(1+mxa[i])*(nb-pos);
    }
    cout<<res<<'\n';
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

