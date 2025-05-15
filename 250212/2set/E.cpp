
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

vc<pii> edges[N];
array<int,3> qs[N]; // {a,b,k}
int dist[400][400]; // w이상의 weight로 k번의 최단경로 
// bool reach_under[400][400]; // w이하의 weight로 임의의 경로
array<int,3> es[N]; // {weight,a,b}
int ans[N];
bool visited[400];
int curw;


void Solve(){
    int n,m,q;
    cin>>n>>m>>q;
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        int a,b,w;
        cin>>a>>b>>w;
        a--, b--;
        edges[a].pb({b,w});
        edges[b].pb({a,w});
        es[i]={w,a,b};
    }   
    rng(i,0,q-1){
        int a,b,k;
        cin>>a>>b>>k;
        a--, b--; 
        qs[i]={a,b,k};
        // a에서 b로 가는 모든 경로 중에서, k번째로 큰 edge
        // 그렇다고 최단경로는 아님. 너무 큰 weight가진 edge들을 피해서 가야 할 수도 있음
        
        // edge하나를 정하고, 이보다 크거나 같은 k-1개 edge로 도달 가능한지. -- 일단 짝수개 차이는 무조건 되는데
        // 홀수개 차이나면 이제 경로에 홀수 사이클이 있어야 하는거같음
        // 이보다 작거나 같은 edge를 무한히 써서 도달 가능한지 -- 이건 쉽다 
    }
    sort(es, es+m);
    reverse(es, es+m);
    fill(ans,ans+q,INF);
    // 전처리를 하면서 해결을 해야 한다.
    int last=m;
    rng(i,0,n-1){
        fill(dist[i],dist[i]+n,INF);
        dist[i][i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            for(auto next: edges[idx]){
                if(dist[i][next.fi]==INF){
                    dist[i][next.fi]=dist[i][idx]+1;
                    q.push(next.fi);
                }
            }
        }
    }

    gnr(i,m-1,0){
        if(!(i==0 || es[i][0]!=es[i-1][0])) continue;
        int w=es[i][0];
        curw=w;
        // cout<<"CURW "<<curw<<'\n';
        // w가 답이라고 생각해보자 
        // w이상의 edge(es에서 [i,last-1]가 새로 추가됨) -> k-1개 이하로 u또는 v와 연결할 수 있는지
        // w이하의 edge -> 그냥 u또는 v와 연결이 되는지
        rng(idx, i, last-1){
            // idx를 더하는 과정은 최대 n^2까지는 인정이다. 
            // 최단경로가 궁금한 게 아니라 [i][j]가 [k]번으로 연결이 되냐 이런거다
            int u=es[idx][1];
            int v=es[idx][2]; // 이제 여기는 dist가 0이 되는 것임.
            rng(a,0,n-1){
                rng(b,0,n-1){
                    dist[a][b]=min(dist[a][b],dist[a][u]+dist[v][b]);
                    dist[b][a]=dist[a][b];
                }
            }
        }

        rng(idx, i, last-1){
            int u=es[idx][1];
            int v=es[idx][2];
            rng(j,0,q-1){
                int a, b, k;
                a=qs[j][0];
                b=qs[j][1];
                k=qs[j][2];
                // cout<<"h1 "<<a+1<<' '<<b+1<<' '<<k<<' '<<u+1<<' '<<v+1<<' '<<dist[a][v]<<' '<<dist[b][u]<<' '<<dist[b][v]<<' '<<dist[a][u]<<'\n';
                if(dist[a][v]+dist[b][u]<=k-1 || dist[b][v]+dist[a][u]<=k-1){
                    ans[j]=min(ans[j],curw);
                }
            }
        }        
        last=i;
    }

    rng(i,0,q-1) cout<<ans[i]<<' ';
    cout<<'\n';
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

