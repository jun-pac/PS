
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

#define N 250001
#define MOD 998244353
#define INF 1000000007 
// random_device rd; 
// mt19937 gen(rd());
// uniform_int_distribution<> dist(0, INF); // random integer from [0, INF] // dist(gen)


int height[501][501];
pair<int, pii> datas[N];
int parent[N];
array<int,4> qs[N];
vc<int> node_to_qs[N]; // node_idx -> qidx
vc<pii> dir;
int ans[N];

int find_root(int idx){
    if(idx==parent[idx]) return idx;
    return parent[idx]=find_root(parent[idx]);
}

void conn(int a, int b, int h){
    if(find_root(a)==find_root(b)) return;
    int ra=find_root(a), rb=find_root(b);
    if(node_to_qs[ra].size() < node_to_qs[rb].size()) swap(ra,rb);
    parent[rb]=ra;
    // ra쪽이 large
    rng(i,0,(int)node_to_qs[rb].size()-1){
        node_to_qs[ra].pb(node_to_qs[rb][i]);
        int qidx=node_to_qs[rb][i];
        int x=qs[qidx][0];
        int y=qs[qidx][2];
        int hx=qs[qidx][1];
        int hy=qs[qidx][3];
        if(find_root(x)==find_root(y)){
            if(h<min(hx,hy)) ans[qidx]=min(ans[qidx],abs(hx-h)+abs(hy-h));
            else ans[qidx]=abs(hx-hy);
        }

    }
}

void Solve(){
    dir.pb({-1,0});
    dir.pb({1,0});
    dir.pb({0,-1});
    dir.pb({0,1});
    int h,w;
    cin>>h>>w;
    rng(i,0,h-1){
        rng(j,0,w-1){
            cin>>height[i][j];
            datas[i*w+j]={height[i][j],{i,j}};
        }
    }
    sort(datas,datas+h*w);
    reverse(datas,datas+h*w); // 높은 것 부터

    rng(i,0,h*w-1) parent[i]=i;
    int q;
    cin>>q;
    fill(ans,ans+q,INF);
    rng(i,0,q-1){
        int a,b,y,c,d,z;
        cin>>a>>b>>y>>c>>d>>z;
        a--, b--, c--, d--;
        qs[i]={a*w+b,y,c*w+d,z};
        node_to_qs[a*w+b].pb(i);
        node_to_qs[c*w+d].pb(i);
        if(a*w+b==c*w+d) ans[i]=abs(y-z);
    }

    // node_to_qs를 small_to_large
    rng(i,0,h*w-1){
        int x=datas[i].se.fi;
        int y=datas[i].se.se;
        rng(k,0,3){
            int nx=x+dir[k].fi;
            int ny=y+dir[k].se;
            if(0<=nx && nx<h && 0<=ny && ny<w && height[nx][ny]>=datas[i].fi){
                conn(nx*w+ny,x*w+y,datas[i].fi);
            }
        }
    }

    rng(i,0,q-1) cout<<ans[i]<<'\n';
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

