
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
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

int datas[55][55];
int a[55], b[55];
int cura[55], curb[55];

#define N 200
#define INF 1000000007

using namespace std;

vector<pair<int,int>> edges[N]; // next, cost. // Must initialize after each testcase
int capa[N][N];
int flow[N][N];
bool inQ[N]; // (inQ[i]) means dist[i] changed ans need to be visited.
int pre[N];
int dist[N];

void add_edge(int a, int b, int w, int f){
    // a->b cost:w capa:f (Reverse edge has negative weight)
    edges[a].push_back({b,w}); capa[a][b]=f; flow[a][b]=0;
    edges[b].push_back({a,-w}); capa[b][a]=0; flow[b][a]=0;
}

void floyd_warshall(int s){
    // Only update pre[], dist[] 
    fill(inQ, inQ+N, false);
    fill(dist, dist+N, INF);
    int ff=INF;
    queue<int> q;
    q.push(s);
    inQ[s]=true; // To maintain light queue
    dist[s]=0;
    while(!q.empty()){
        int idx=q.front(); inQ[idx]=false;
        q.pop();
        for(int i=0; i<edges[idx].size(); i++){
            int next=edges[idx][i].first, w=edges[idx][i].second; 
            if(capa[idx][next]-flow[idx][next]>0 && dist[idx]+w<dist[next]){
                dist[next]=dist[idx]+w;
                pre[next]=idx;
                if(!inQ[next]) q.push(next);
                inQ[next]=true;
            }
        }
        
    }
}

pii MCMF(int s, int t){
    // Return minimum cost for maximum flow
    int res=0, resf=0;
    while(true){
        floyd_warshall(s);
        if(dist[t]==INF) break;
        // Get flow
        int cur=t, ff=INF;
        while(cur!=s){
            ff=min(ff,capa[pre[cur]][cur]-flow[pre[cur]][cur]);
            cur=pre[cur];
        }
        // Flow update
        cur=t;
        while(cur!=s){
            flow[pre[cur]][cur]+=ff;
            flow[cur][pre[cur]]-=ff;
            cur=pre[cur];
        }
        res+=dist[t]*ff;
        resf+=ff;
    }
    return {res,resf};
}


void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1){
        rng(j,0,m-1){
            cin>>datas[i][j];
        }
    }
    int sum=0, sumb=0, cursum=0;
    rng(i,0,n-1){
        rng(j,0,m-1){
            cursum+=datas[i][j];
        }
    }
    rng(i,0,n-1){
        cin>>a[i];
        sum+=a[i];
    }
    rng(j,0,m-1){
        cin>>b[j];
        sumb+=b[j];
    }
    if(sum!=sumb){
        cout<<-1<<'\n';
        return;
    }
 
    // MCMF
    rng(i,0,n-1){
        add_edge(100,i,0,a[i]);
    }
    rng(i,0,m-1){
        add_edge(i+50,101,0,b[i]);
    }    
    rng(i,0,n-1){
        rng(j,0,m-1){
            if(datas[i][j]==1) add_edge(i,j+50,-1,1);
            else add_edge(i,j+50,1,1);
        }
    }
    pii res=MCMF(100,101);
    if(res.se==sum && res.se==sumb){
        cout<<cursum+res.fi<<'\n';
    }
    else cout<<-1<<'\n';
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

