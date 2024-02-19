
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

vc<int> edges[N];
array<int,3> sedges[N];
int n,m;
int parent[N];
bool visited[N];

int find(int idx){
	if(idx==parent[idx]) return idx;
	return parent[idx]=find(parent[idx]);
}
void c_union(int a, int b){
	a=find(a), b=find(b);
	parent[b]=a;
}
int pred[N];

bool DFS(int idx, int p, int t){
    if(visited[idx]) return 0;
    visited[idx]=1;
    pred[idx]=p;
    if(idx==t) return 1;
    for(auto next : edges[idx]){
        if(!visited[next]){
            if(DFS(next, idx, t)) return 1;
        }
    }
    return 0;
}

void Solve(){
    cin>>n>>m;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        int a,b,w;
        cin>>a>>b>>w;
        a--, b--;
        sedges[i]={w,a,b};
    }
    sort(sedges,sedges+m);

    rng(i,0,n-1) parent[i]=i;
    array<int,3> cut_edge={-1,-1,-1};
    int lastw=INF;
    gnr(i,m-1,0){
        int a=sedges[i][1], b=sedges[i][2], w=sedges[i][0];
        if(find(a)==find(b)){
            cut_edge=sedges[i];
        }
        c_union(a,b);
        edges[b].pb(a);
        edges[a].pb(b);
    }

    assert(cut_edge[0]!=-1);
    int a=cut_edge[1], b=cut_edge[2];
    assert(a!=b);
    //cout<<"cut "<<a<<' '<<b<<' '<<cut_edge[0]<<endl;
    rng(i,0,m-1){
        if(!(sedges[i][1]==a && sedges[i][2]==b)){
            edges[sedges[i][1]].pb(sedges[i][2]);
            edges[sedges[i][2]].pb(sedges[i][1]);
        }
    }
    fill(visited,visited+n,0);
    //cout<<"this? "<<DFS(a,-1,b)<<endl;
    assert(DFS(a,-1,b));
    vc<int> ans;
    //cout<<"imp "<<a<<' '<<pred[b]<<' '<<pred[pred[b]]<<'\n';
    int cc=b;
    while(cc!=-1){
        ans.pb(cc);
        cc=pred[cc];
    }
    assert(ans.size()>=3);

    cout<<cut_edge[0]<<' '<<ans.size()<<'\n';
    rng(i,0,(int)ans.size()-1) cout<<ans[i]+1<<' '; cout<<'\n';
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

