
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 

vc<int> edges[N];
int mxd, mxidx; 
int cent1, cent2;

void DFS1(int idx, int p, int d){
    if(d>mxd){
        mxd=d;
        mxidx=idx;
    }
    for(auto next : edges[idx]){
        if(next!=p) DFS1(next,idx,d+1);
    }
}

int DFS2(int idx, int p, int d){
    int cur=0;
    for(auto next : edges[idx]){
        if(next!=p) cur=max(cur,DFS2(next,idx,d+1));
    }
    if(cur==mxd/2) cent1=idx;
    if(cur==mxd/2+1) cent2=idx;
    if(idx==mxidx) return 1;
    if(cur!=0) return cur+1;
}

void Solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<1<<'\n';
        cout<<1<<' '<<0<<'\n';
        return;
    }
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        //cout<<a<<' '<<b<<'\n';
        edges[a].pb(b);
        edges[b].pb(a);
    }
    mxd=-1, mxidx=-1;
    DFS1(0,-1,0);
    int V=mxidx;
    mxd=-1, mxidx=-1;
    DFS1(V,-1,0);
    DFS2(V,-1,0);
    //cout<<V+1<<'\n';
    //cout<<"CENT : "<<cent1+1<<' '<<cent2+1<<'\n';


    if(mxd%4==1){
        // 두 개의 cent
        int num=mxd/2+2;
        cout<<num<<'\n';
        rng(i,0,num-1){
            cout<<cent1+1<<' '<<i<<'\n';
        }
    }
    else if(mxd%4==3){
        int num=mxd/2+1;
        cout<<num<<'\n';
        rng(i,0,num){
            if(i%2==1){
                cout<<cent1+1<<' '<<i<<'\n';
                cout<<cent2+1<<' '<<i<<'\n';
            }
        }
    }
    else{
        // cent1만 의미있음.
        int num=mxd/2+1;
        cout<<num<<'\n';
        rng(i,0,num-1){
            cout<<cent1+1<<' '<<i<<'\n';
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

