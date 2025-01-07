
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

#define N 500030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N];
vc<int> DP[N];
int sz[N];
int offset[N];
int mx_depth[N];

void DFS(int idx, int p, int d){ 
    int mxidx=idx;
    sz[idx]=1;
    mx_depth[idx]=d;
    for(auto next : edges[idx]){
        if(next!=p){
            DFS(next,idx,d+1);
            mx_depth[idx]=max(mx_depth[idx],mx_depth[next]);
            sz[idx]+=sz[next];
            if(DP[next].size()>DP[mxidx].size()){ // same as mx_depth
                mxidx=next;
            }
        }
    }
    swap(DP[mxidx],DP[idx]);

    // small to large
    offset[idx]=offset[mxidx];
    for(auto next : edges[idx]){
        if(next!=p && next!=mxidx){
            offset[idx]+=sz[next];
        }
    }
    //if(DP[idx].size()!=0) cout<<"DP[0]: "<<DP[idx][0]<<' '<<offset[idx]<<'\n';

    for(auto next : edges[idx]){
        if(next!=p && next!=mxidx){
            rng(i,0,(int)DP[next].size()-1){
                
                int newi=i+mx_depth[mxidx]-mx_depth[next];
                //cout<<"here "<<newi<<' '<<DP[next][i]+offset[next]<<'\n';
                DP[idx][newi]+=DP[next][i]+offset[next]-sz[next];
            }
        }
    }
    DP[idx].push_back(sz[idx]-1-offset[idx]);    
    //cout<<"cur idx "<<idx+1<<' '<<d<<' '<<mx_depth[idx]<<' '<<sz[idx]<<' '<<offset[idx]<<endl;
    // rng(i,0,(int)DP[idx].size()-1) cout<<DP[idx][i]+offset[idx]<<' ';
    // cout<<endl;
}

void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) DP[i].clear();
    rng(i,0,n-1) offset[i]=0;
    rng(i,0,n-2){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
        edges[b].pb(a);
    }

    int s=0;
    DFS(0,-1,0);
    int mn=INF;
    rng(i,0,(int)DP[0].size()-1){
        mn=min(mn,DP[0][i]+offset[0]);
    }
    cout<<mn<<'\n';
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

