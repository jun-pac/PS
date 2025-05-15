
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

vc<int> edges[N];
pii es[N];
int parent[N];
int find_root(int idx){
    if(parent[idx]==idx) return idx;
    return parent[idx]=find_root(parent[idx]);
}

int essen[N];
int comp_num[N];
vc<int> comp_es[N];
int valid_num[N];
set<int> roots;

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        es[i]={a,b};
        edges[a].pb(b);
        edges[b].pb(a);
    }
    rng(i,0,n-1) parent[i]=i;
    fill(essen,essen+n,0);
    int cnt=0;
    rng(i,0,m-1){
        int a=es[i].fi, b=es[i].se;
        if(find_root(a)!=find_root(b)){
            essen[i]=1;
            parent[find_root(a)]=find_root(b);
            cnt++;
        }
    }
    rng(i,0,n-1){
        roots.insert(find_root(i));
    }


    cout<<n-1-cnt<<'\n';
    rng(i,0,m-1){
        int a=es[i].fi, b=es[i].se;
        if(roots.size()==1) break;
        if(!essen[i]){
            int curroot=find_root(a);
            int otherroot;
            if((*roots.begin())==curroot){
                otherroot = *next(roots.begin());
            }
            else{
                otherroot = *prev(roots.find(curroot));
            }
            cout<<i+1<<' '<<a+1<<' '<<otherroot+1<<'\n';
            parent[curroot]=otherroot;
            roots.erase(curroot);
        }
    }
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

