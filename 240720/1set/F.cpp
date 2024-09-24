
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
#define N_PRIME 200020
__attribute__((optimize("Ofast,unroll-loops"),target("avx,avx2,fma")))

int datas[N];
string s;
vc<int> edges[N];
bool visited[N];
int scc_idx[N];
int cnt,temp;
int cnt_scc[N];
vc<int> sccs[N];
#define N_PRIME 200020

bool is_prime[N_PRIME];
vector<int> primes;
int mx[N_PRIME];
int pcnt;

void build_prime(int n){
    // n<N_PRIME
    pcnt=0;
    fill(is_prime+2,is_prime+n+1,true);
    for(int i=2; i<=n; i++){
        if(!is_prime[i]) continue;
        for(int j=2; i*j<=n; j++) is_prime[i*j]=false;
    }
    for(int i=2; i<=n; i++) if(is_prime[i]){
        primes.push_back(i);
        pcnt++;
    }
}


void DFS(int idx){
    if(visited[idx]) return;
    visited[idx]=1;
    temp++;
    scc_idx[idx]=cnt;
    sccs[cnt].pb(idx);

    for(auto next : edges[idx]){
        if(!visited[next]) DFS(next);
    }
}

void Solve(){
    int n;
    cin>>n;
    cin>>s;
    rng(i,0,n-1){
        cin>>datas[i];
        datas[i]--;
        edges[i].pb(datas[i]);
    }
    fill(visited,visited+N,0);
    cnt=0;
    rng(i,0,n-1){
        if(!visited[i]){
            temp=0;
            DFS(i);
            cnt_scc[cnt]=temp;
            cnt++;
        }
    }
    rng(i,0,cnt-1){
        int val=cnt_scc[i];
        rng(j,0,pcnt-1){
            int temp=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    //cin>>t;
    build_prime(200000);
    while(t--){
        Solve();
    }
    return 0;
}

