
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
int dist[400][400]; // w�̻��� weight�� k���� �ִܰ�� 
// bool reach_under[400][400]; // w������ weight�� ������ ���
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
        // a���� b�� ���� ��� ��� �߿���, k��°�� ū edge
        // �׷��ٰ� �ִܰ�δ� �ƴ�. �ʹ� ū weight���� edge���� ���ؼ� ���� �� ���� ����
        
        // edge�ϳ��� ���ϰ�, �̺��� ũ�ų� ���� k-1�� edge�� ���� ��������. -- �ϴ� ¦���� ���̴� ������ �Ǵµ�
        // Ȧ���� ���̳��� ���� ��ο� Ȧ�� ����Ŭ�� �־�� �ϴ°Ű���
        // �̺��� �۰ų� ���� edge�� ������ �Ἥ ���� �������� -- �̰� ���� 
    }
    sort(es, es+m);
    reverse(es, es+m);
    fill(ans,ans+q,INF);
    // ��ó���� �ϸ鼭 �ذ��� �ؾ� �Ѵ�.
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
        // w�� ���̶�� �����غ��� 
        // w�̻��� edge(es���� [i,last-1]�� ���� �߰���) -> k-1�� ���Ϸ� u�Ǵ� v�� ������ �� �ִ���
        // w������ edge -> �׳� u�Ǵ� v�� ������ �Ǵ���
        rng(idx, i, last-1){
            // idx�� ���ϴ� ������ �ִ� n^2������ �����̴�. 
            // �ִܰ�ΰ� �ñ��� �� �ƴ϶� [i][j]�� [k]������ ������ �ǳ� �̷��Ŵ�
            int u=es[idx][1];
            int v=es[idx][2]; // ���� ����� dist�� 0�� �Ǵ� ����.
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

