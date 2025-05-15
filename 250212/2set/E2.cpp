
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
int dist[400][400][400]; // w�̻��� weight�� k���� �ִܰ�� 
int curw[400];
array<int,3> es[N]; // {weight,a,b}
int parent[N];

int find_root(int x){
    if(parent[x]==x) return x;
    return parent[x]=find_root(parent[x]);
}


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
    }
    sort(es, es+m); 

    int wcnt=0;
    curw[wcnt]=-1; // ������� �� ���� ���� �ʳ� 
    // dist[0][i][j]�� �ʱ� �ִܰŸ��� ä���
    rng(i,0,n-1){
        fill(dist[wcnt][i],dist[wcnt][i]+n,INF);
        dist[wcnt][i][i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int idx=q.front();
            q.pop();
            for(auto next: edges[idx]){
                if(dist[wcnt][i][next.fi]==INF){
                    dist[wcnt][i][next.fi]=dist[wcnt][i][idx]+1;
                    q.push(next.fi);
                }
            }
        }
    }
    wcnt++;

    rng(i,0,n-1) parent[i]=i;
    rng(i,0,m-1){
        int w=es[i][0], u=es[i][1], v=es[i][2];
        if(find_root(u)==find_root(v)) continue;
        parent[find_root(u)]=find_root(v);
        curw[wcnt]=w;
        // dist[wcnt][i][j]������ curw[wcnt]������ ������ dist�� 0���� ��޵� ���� dist�� ����
        rng(a,0,n-1){
            rng(b,a,n-1){
                dist[wcnt][a][b]=min(dist[wcnt-1][a][b],min(dist[wcnt-1][a][u]+dist[wcnt-1][v][b],dist[wcnt-1][a][v]+dist[wcnt-1][u][b]));
                dist[wcnt][b][a]=dist[wcnt][a][b];
            }
        }
        wcnt++;
    }

    // ans�� ���⼭�� �̺�Ž������ ���ؾ� ��. t��° distance table���� i�� j�� �Ÿ��� k-1���϶��,
    // �� curw[t]�� ���� �� curw[t]���� ū ���� k-1���Ϸ� ������ �ȴٸ�, �� curw[t]�� ���� �� �� ����
    // �����δ� ���� curw[t]�� �ֵ��� dist�� �ݿ��� �Ǿ� �����ϱ� 
    // t�� Ŀ���� Ŀ������ �� ����Ȯ���� ������, �׷� ans�� ���� Ŀ���ϱ� ������ �ִ°���
    // �츮�� ���� ���� ���ϰ� ���� �Ŵϱ�.
    // ����� �׷��� ���� curw[t]�� ������ �ֵ� �߿����� ���� �������� ���� �������. ���� ������ curw[t]�� ��.
    // cout<<"WCNT "<<wcnt<<'\n';
    // rng(i,0,n-1) cout<<"WCNT: "<<curw[i]<<' '<<dist[i][7][1]<<' '<<dist[i][1][7]<<'\n';
    rng(i,0,q-1){
        int a,b,k;
        a=qs[i][0], b=qs[i][1], k=qs[i][2];
        int l=0, r=wcnt-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(dist[mid][a][b]>k-1) l=mid+1;
            else r=mid;
        }
        cout<<curw[l]<<' ';
    }
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

