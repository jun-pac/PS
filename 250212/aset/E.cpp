
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

#define N 400030
#define MOD 998244353
#define INF 1000000007 
random_device rd; 
mt19937 gen(rd());
uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)

vc<int> edges[N];
int datas[N];
array<int,3> sdatas[N];
int depth[N];
int parent[N];
int vcnt[N];

void DFS(int idx, int p, int d){
    // "내 아래의 모든 노드가 나 이상의 값을 가짐, 나보다 큰 모든 노드는 내 아래에 있음"
    depth[idx]=d;
    parent[idx]=p;
    for(auto next: edges[idx]){
        if(next==p) continue;
        DFS(next,idx,d+1);
    }
}

int visited[N];

int DFS2(int idx, int p){
    int cnt=visited[idx];
    for(auto next : edges[idx]){
        if(next!=p) cnt+=DFS2(next,idx);
    }
    vcnt[idx]=cnt;
    return cnt;
}


void Solve(){
    int n;
    cin>>n;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,n-1) cin>>datas[i];
    // 큰 것 순으로 방문을 하다가, 위가 먼저 방문되면 안된다. (같은 값이면 큰 depth부터 방문하도록 함)
    // subsz와 현재까지 cnt가 같아야 함.

    rng(i,0,n-2){
        int u,v;
        cin>>u>>v;
        u--, v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    DFS(0,-1,0);
    rng(i,0,n-1) sdatas[i]={datas[i],depth[i],i};
    sort(sdatas,sdatas+n);
    int largest=sdatas[n-1][0];
    fill(visited,visited+n,0);
    int lastp=-1;
    int pcnt=0;
    gnr(i,n-1,0){
        int idx=sdatas[i][2];
        // cout<<"IDX "<<idx<<endl;
        if(datas[idx]==largest){
            pcnt++;
            visited[idx]=1;
        }
    }
    DFS2(0,-1);
    rng(i,0,n-1){
        if(vcnt[sdatas[i][2]]==pcnt) lastp=sdatas[i][2];   
    }
    if(pcnt==n){
        cout<<0<<'\n';
        return;
    }
    if(lastp==-1){
        // cout<<"PCNT "<<pcnt<<'\n';
        cout<<sdatas[n-pcnt-1][2]+1<<'\n';
        return;
    }
    // cout<<"LASTP "<<lastp<<'\n';
    gnr(i,n-1-pcnt,0){
        int idx=sdatas[i][2];
        // lastp에서 parent로 올라서 idx가 되는가?
        while(lastp!=-1 && lastp!=idx) lastp=parent[lastp];
        if(lastp==-1){
            cout<<idx+1<<'\n';
            return;
        }
        // lastp==idx임.
    }
    cout<<0<<'\n';
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

