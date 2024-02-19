
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

#define N 3030
#define MOD 998244353
#define INF 1000000007 

ll datas[N];
vc<int> edges[N];
int order[N];
int cnt;
bool visited[N];

void DFS(int idx){
    visited[idx]=1;
    for(int next : edges[idx]){
        if(!visited[next]) DFS(next);
    }
    order[cnt++]=idx;
}

// ������ ��忡 {start time, number}�� pair���� �����ϰ�, greedy�ϰ� �տ������� 1�� ����� �ϸ� �� �������� �������� �ð��� �� �� ����.
vc<pll> packet[N];
ll LT[N]; // last time

void Solve(){
    int n,m;
    cin>>n>>m;
    rng(i,0,n-1) cin>>datas[i];
    rng(i,0,n-1) edges[i].clear();
    rng(i,0,m-1){
        int a,b;
        cin>>a>>b;
        a--, b--;
        edges[a].pb(b);
    }
    cnt=0;
    fill(visited,visited+n,0);
    rng(i,0,n-1) if(!visited[i]) DFS(i);
    reverse(order,order+n);

    rng(i,0,n-1){
        packet[i].clear();
        packet[i].pb({0,datas[i]});
    }

    //rng(i,0,n-1) cout<<order[i]<<' '; cout<<'\n';
    rng(i,0,n-1){
        int idx=order[i];
        sort(all(packet[idx])); // st�� ��û���� ũ�� sort�� ���ϴ� �� �ƴѰ�
        // volume�� st�� ������ modify�� ������ �־ MOD�ع����� �ȵ� �� ������
        // st�� ������ ó���� st���� ��� ������ ���� �� �ƴѰ�
        // �� �ƴѵ� n���� ũ���� ������

        ll volume, st;
        int j=0;
        while(j<(int)packet[idx].size()){
            st=packet[idx][j].fi;
            //assert(st<=n);
            volume=packet[idx][j].se;
            j++;
            while(j<(int)packet[idx].size() && st+volume>=packet[idx][j].fi){
                volume+=packet[idx][j].se;
                j++;
            }
            //assert(volume<=2000000LL*MOD);
            if(volume!=0){
                for(int next : edges[idx]){
                    if(volume>MOD) packet[next].pb({st+1,volume%MOD+MOD});
                    else packet[next].pb({st+1,volume});
                }
            }
            
            // ���е� packet�� n������ ���� �� ���� ��. �ý��� ���ؿ��� ������ st���� n����
            // �ٵ� �װ� ��濡�� �����ϱ� ������ n^2���� ���μ��� �ؾ��Ҽ��� �ִµ�..
            // n^3�� �� �ʿ��Ѱ����� ������ �غ��ڰ��
            // �ƴ��� ������ edges�� ���� pair�� �ִ� n���� ������ �ִ� mn���� ������ �ϴ� ������
        }
        LT[idx]=(st+volume)%MOD;
    }
    cout<<(LT[order[n-1]]+MOD)%MOD<<'\n';
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