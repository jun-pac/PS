
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

pii dirs[4];
string datas[62];
bool visited[62][62];
int min_dist[4000][4000];
int n;

void DFS(pii pos){
    if(visited[pos.fi][pos.se]) return;
    visited[pos.fi][pos.se]=1;
    rng(i,0,3){
        int nx=pos.fi+dirs[i].fi, ny=pos.se+dirs[i].se;
        if(0<=nx && nx<n && 0<=ny && ny<n){
            if(datas[nx][ny]!='#' && !visited[nx][ny]) DFS({nx,ny});
        }
    }
}

void Solve(){
    dirs[0]={-1,0};
    dirs[1]={0,1};
    dirs[2]={1,0};
    dirs[3]={0,-1};
    cin>>n;
    assert(n<=60);
    rng(i,0,n-1) cin>>datas[i];
    pii p1={-1,-1},p2={-1,-1};
    rng(i,0,n-1){
        rng(j,0,n-1){
            if(datas[i][j]=='P' && p1.fi==-1){
                p1={i,j};
            }
            else if(datas[i][j]=='P'){
                p2={i,j};
            }
        }
    }
    assert(p1.fi!=-1 && p2.fi!=-1);

    //cout<<"p1 p2 "<<p1.fi<<' '<<p1.se<<' '<<p2.fi<<' '<<p2.se<<'\n';
    DFS(p1);
    if(!visited[p2.fi][p2.se]){
        cout<<-1<<'\n';
        return;
    }
    
    // BFS
    queue<pair<pii,int>> qs;
    int nn=n*n;
    rng(i,0,nn-1){
        fill(min_dist[i],min_dist[i]+nn,INF);
    }
    qs.push({{p1.fi*n+p1.se,p2.fi*n+p2.se},0});
    while(!qs.empty()){
        auto cur=qs.front();
        qs.pop();
        if(min_dist[cur.fi.fi][cur.fi.se]!=INF) continue;
        min_dist[cur.fi.fi][cur.fi.se]=cur.se;
        int x1=cur.fi.fi/n, y1=cur.fi.fi%n;
        int x2=cur.fi.se/n, y2=cur.fi.se%n;
        if(cur.fi.fi==cur.fi.se){
            cout<<cur.se<<'\n';
            return;
        }
        int nx1, nx2, ny1, ny2;
        rng(i,0,3){
            nx1=x1+dirs[i].fi;
            ny1=y1+dirs[i].se;
            nx2=x2+dirs[i].fi;
            ny2=y2+dirs[i].se;
            if(!(0<=nx1 && nx1<n && 0<=ny1 && ny1<n)) nx1=x1, ny1=y1;
            else if(datas[nx1][ny1]=='#') nx1=x1, ny1=y1;
            if(!(0<=nx2 && nx2<n && 0<=ny2 && ny2<n)) nx2=x2, ny2=y2;
            else if(datas[nx2][ny2]=='#') nx2=x2, ny2=y2;
            if(min_dist[nx1*n+ny1][nx2*n+ny2]==INF) qs.push({{nx1*n+ny1,nx2*n+ny2},cur.se+1});
        }
    }
    cout<<-1<<'\n';
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

